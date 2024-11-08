## 服务证书生成：

至少2048bit

```
openssl genrsa  -out server.key 2048
```

## 生成请求文件：

- Organization Name(O)：申请单位名称法定名称，可以是中文或英文
- Organization Unit(OU)：申请单位的所在部门，可以是中文或英文
- Country Code(C)：申请单位国家，只能是两个字母的国家码，如中国只能是：CN
- State or Province(S)：申请单位所在省名或州名，可以是中文或英文
- Locality(L)：申请单位所在城市名，可以是中文或英文
- **Common Name(CN)：最关键！！！**申请SSL证书的具体网站域名
- challenge password：挑战密码，数字签名认证是用的，目前不知道怎么使用，存疑。

```
openssl req -new -key server.key  -out pub.csr -config csr.conf
```

CN填申请域名：winscloud-dongguan.huawei.com
其中拓展字段中的DNS可以写域名或者*.huawei.com作为域名的拓展。
IP字段用于IP识别。

```
#csr.conf
[ req ] 
prompt = no 
req_extensions = v3_ext 
distinguished_name = dn 
   
[ dn ] 
C = CN 
ST = GuangDong
L = DongGuan 
O = ICSL 
OU = ICSL 
CN = winscloud-dongguan.huawei.com
   
[ req_ext ] 
subjectAltName = @alt_names 
   
[ alt_names ] 
DNS.1 = winscloud-dongguan.huawei.com
IP.1 = 172.29.228.36
   
[ v3_ext ] 
subjectAltName=@alt_names
```

> v3_ext千万不能增加extendedKeyUsage=serverAuth,clientAuth 
> 对于浏览器而言，这样设置为双向认证，这样即使证书和CA配套，且安装到系统，也会出现tls建链失败，客户端返回illegal Parameter的告警。
> 奇怪的是，对于curl命令进行访问没有问题

## 创建CA私钥：

```
openssl genrsa -out myca.key 2048
```

CA请求文件：这里只是用配置文件，省略手动填信息

```
openssl req -new -key myca.key -out myca.csr -config ca.conf
```

```
#ca.conf
[ req ]
prompt = no
req_extensions = v3_ca
distinguished_name = dn

[ dn ]
O = ICSL 
CN = root

[ v3_ca ]
basicConstraints = CA:TRUE
keyUsage = keyCertSign, cRLSign
```

-extfile增加CA专用字段，貌似可以不加

```
openssl x509 -days 3650 -req -in myca.csr -signkey myca.key -out myca.crt -extfile <(echo "basicConstraints=CA:TRUE")
```

增加SAN签发，拓展DNS网址
其中-extfile csr.conf为添加dns网址和ip，同时需要添加-extensions v3_ext，让其生效

```
openssl x509 -days 3650 -req -in pub.csr -CAkey myca.key -CA myca.crt -CAcreateserial -extensions v3_ext -out server.crt -extfile csr.conf
```

## 校验证书和CA

签发完成校验证书和CA的对应关系，并查看server.crt的信息
注意：如果服务证书不是由该CA签发，客户端校验证书TLS会提示Alert告警，显示certificate unkown，而从curl命令中可以直接看到CA unvalid的提示，便于快速定位问题。

```
openssl verify -CAfile myca.crt server.crt
openssl x509 -in server.crt -noout -text
```

最简单的验证方式，使用curl命令，同时可以用-v选项打出TLS建链失败的原因

```
curl --cacert myca.crt -v https://172.29.228.36
```

## windows安装根CA证书

最后双击myca.crt安装到windows系统根证书即可。
