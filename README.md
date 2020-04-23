# Rigth Now
[[C语言进阶学习](https://github.com/zhoutaoccu/Software-skills/blob/master/C/C_basic.md)]
1.  变量
2.  表达式


# 旧卡丑Sourceinsight替代品 ：Visual Studio Code(VS Code)
- 安装简单，而且开源免费，主要是插件比较多，比较方便。一下主要从功能和命令方面讲怎么从SI转到VS Code.
- 插件必安装：1.Setting Sync 2.C/C++(官方编译器，这样才能支持函数和符号查找) 3.Chinese Language语言包 4.Python执行器 5.Leetcode刷题插件 6.TODO高亮需求开发
- 代码高亮 - VS code换主题换不同的高亮颜色，双击变量即可突出显示
- 代码工程都是以文件夹为工程区分，直接新建页面然后添加文件夹即可，无需新建工程
- 代码也可全文件夹搜索替换，效率极高Ctrl+Shift+F/H。本文件查找替換去掉Shift。可以用F3下一个或者Shift+F3前一个。全文件还未知
- 可用Ctrl+P进行文件名的搜索，Ctrl+Shift+O进行符号（变量和函数名称）搜索。在搜索框中加@等效查符号，>表示执行插件的命令，@：可以符号进行分类

# Pycharm ：Python 最好IDE，没有之一
- 专业版只需在官网验证自己的校园邮箱即可，然后每年再重新邮箱验证即可。还是校园邮箱大法好啊！！专业版比如一些数据可视化工具之类，功能比较全面。
- 新建工程，可以直接选择本地python编译器，也可以选择虚拟环境编译器，就是在你工程文件夹下新建一个环境，这样就可以工程相互不干扰，高端玩家必备，小白就别整这些复杂的了。
- 主题文字设置。Dacula深色主题比较装逼，主要是不伤眼吧。字体选择consolas 12-16pt比较万能的字体，反正matlab我也这么设置了。多说几句护眼的话，对于我们这种夜猫子来说，这个用眼千日，用脑一时，可能打字，或者动手写字的时候是最不费眼的时候了，晚上基本都是主要的作战时间，早起不可能，所以这个保护眼睛就极其重要。一个，windows窗口可以[设置护眼色](https://jingyan.baidu.com/article/8cdccae9438422315413cde1.html)，还有就是win10系统->显示设置里有个夜灯的功能，和ipad那个护眼一样，可以设置夜晚自动开启，当然还极力推荐那个橙色的系统主题色，让我感觉，暖暖的，很贴心。
- 再比较一下spyder吧。本来安装anaconda默认就自带了，而且轻量级也准备用了，其主要特点就是基于Ipython结果再用Tensorflow的时候遇到警告然后就崩溃了，重装软件都不行，然后就弃坑了，本来觉得它唯一的亮点就是方便查看变量值，但是发现Pycharm也可以看变量值，然后对于机器学习，数据挖掘的可视化也做的不较好，所以就放弃它了。
- 快捷键设置。setting->keymap 这个非常重要，对于用的语言类型多的，各个软件默认设置不一致，会导致很多不习惯，每个人喜好可能不同，这里推荐几个改键，同时也重申一下重要的快捷键。一般常用的就那几个，然后软件还把一些很方便的键给默认了，很不爽。  
1.注释行(comment with line，搜索即可，右键第一个)，修改或者添加为Ctrl+R，提示就不用管了，主要一个单手可以操作，然后这个是matlab默认键。   
2.删除行(delete line)，修改为Ctrl+Q,还记得以前总是按backspace按心酸，特别是一些很长的缩进，删完光标直接调到下一行末尾。  
3.重复光标所在行，这个就是excel的操作，但是使用，默认即有Ctrl+D  
4.反缩进，Shift+Tab，这个是默认的，很好用。而且可以直接光标随便点一行的任何地方，都是默认整体反缩进，Tab就不行了。  
5.运行(Run),修改为F5，matlab习惯了  
6.Debug还有单步啥的也可以改，但是我感觉还是鼠标直观，默认的F8单步就挺好了  

# Notepad++ ：最好代码查看神器+编辑器，没有之一
- Setup Notepad++,which is a convenient edit tool to read and edit any kind of code.Set the theme as Obsidian and font as Consoles 14 pt.
- Notepad++ is suitable for beginners to study C/C++, you can install [MinGW-W64](https://sourceforge.net/projects/mingw-w64/?source=typ_redirect)(including gcc,g++,gdb) for compiling. [setup tips for choose the right options](https://zhidao.baidu.com/question/1382951261644564380.html)[How to install it?](https://jingyan.baidu.com/article/19192ad816ea01e53e570730.html)It not only works well in C/C++ competition, but also can be applied to [MATLAB](https://zhuanlan.zhihu.com/p/30485050) in which you can compile c code to MinGW64 file used to work in .m file.
- After installing MinGW-W64 and finished your C/C++ code in notepad++, click RUN(F5). And you need input something to compile and run the code, after that, rename them and add shortcut for convenience. 
- [F5]Input 'cmd /k gcc -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(FULL_CURRENT_PATH)" && CLS && "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" & PAUSE & EXIT' for C code.
- [Ctrl+F5]Input 'cmd /k g++ -o "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" "$(FULL_CURRENT_PATH)" && CLS && "$(CURRENT_DIRECTORY)\$(NAME_PART).exe" & PAUSE & EXIT' for C++ code.
- [F9]Input 'gdb $(CURRENT_DIRECTORY)\$(NAME_PART).exe' for debugging program.
- [F6]Input 'cmd /k python "$(FULL_CURRENT_PATH)" & ECHO. & PAUSE & EXIT' for python code.
- [Shift + F9] '"$(FULL_CURRENT_PATH)" >$(CURRENT_DIRECTORY)\$(NAME_PART)_output.txt && "C:\FastSpeedAPP\Notepad++\notepad++.exe" $(CURRENT_DIRECTORY)\$(NAME_PART)_output.txt' for run .bat script.
- Add -g in front of -o to make sure the success process of gdb.

# SourceInsight ：最好的工程项目代码查看神器，没有之一
- [Sourceinsight 4.0 Download and Setup](https://blog.csdn.net/biubiuibiu/article/details/78044232), I have copy it to my Baiduyun,uncompress code is "biu".
- It has advantages of clear function display and going to the definition of functions quickly (even not in the same file), you can search (or lookup reference the function name) the variable through all the project files, by clicking the red link label, you can switch between the function name and the use of function. In the process of jumps here and there, Go forward and go back are also allowed.  
- The software is best for C/C++, but you can download python.cls to suit for python language. Enjoy your Code study.
- New Project and choose the project file directory, and it will create some new project files.
- [User Guider](https://blog.csdn.net/qq_32693119/article/details/79963069)

# Beyond Compare ：最好的项目文件代码对比神器，没有之一
- Beyond Compare 4 is available in the official website, and we can try it without limitation. 
- It is similar to the difference comparing in the SVN,but the most exciting feature is that the software can compare the whole project file one by one, you just compare those step by step. And it will save the compare, you can see it next 

# Docker : Double system and virtual system can be substituted.
Study for raspberry os using gcc-aarch64-linux-gnu compile kernel by myself.

Following website add to docker Daemon list.  
https://registry.docker-cn.com  
https://dockerhub.azk8s.cn

1.Download and setup docker for windows10 pro version, not docker_toolbox.
https://download.docker.com/win/stable/Docker%20for%20Windows%20Installer.exe 
https://jingyan.baidu.com/article/0f5fb0995f77fc6d8334eabb.html

2.Install Docker image by github man after edit Daemon server list.
https://hub.docker.com/r/smatyukevich/raspberry-pi-os-builder/dockerfile

3.Add date hardware to docker images after set password for win10.  
docker run --rm -v F:\3#HUAWEI2019\raspberry-pi-os\:/data smatyukevich/raspberry-pi-os-builder ls /data

docker run -v F:/3#HUAWEI2019/raspberry-pi-os:/data smatyukevich/raspberry-pi-os-builder ls /data


3.setup error solutions.  
https://cloud.tencent.com/developer/article/1355198



# Mathtype ：最好公式编辑器，没有之一
- Latest Mathtype with office 2016 is not a good choice, you must pay a lot to purchase the license. Maybe you can download a free old version of Mathtype6.9b. Now I want to show you how to slove some problem to use mathrype6.9b with office 2016.
- 1.Make a New mathtype file (.wmf), and later we will make it like a editor just like word. But first you should set the size of you equel(10pt,Size->Define->10pt), and set the setting for new equal.(P->E->for new file) ,and if you do this at the end, you can change the size and save the setting for all your document to change all the size. However, you need the latest version,and set in the word->mathtype.
- 2.Editor you equal among the words, and copy it to the Word2016 you like. Remember you should set the style of parameter firstly. Because the style  will change if you add a equel. After you add the equel, you should not to apply the style again. If you do this, the equel will up and down in the word. Worestly, if you save it ,and open it again, the equal will not work, and it is just a pictrue. What a shame！
- 3.If you edit a big equel ,and it is over a line. You want it in the center, and make a number index for it, you'd better download a old version of word or WPS, add the equel in the word->mathtype_pulgs. It is perfect, this can not be achieved by old version of mathtype! 

# MobaXterm ：最好的SSH远程访问服务器（甚至本机上的虚拟机）的工具
- MobaXterm is a fantastic tool for Linux server study, it is free for basic use. Given by IP and password, you can connect the server through ssh. Combined with VMware Workstation 14 Player(A free software for virtual machine for personal use, much small than VMware workstation), we can use linux in the windows OS very conviently, exchanging files, seeing files struct, pasting command code.
- MobaXterm is very easy to use, but in the VMware play, which type of linux to use, how to connect the Internet and how to set the SSH are the problem to be sovled. Therefore, the "Linux_study.txt" file should be read later.

# Google Scholar ：科研查文献少不了
- Search Tips: If you want to search a paper that including two key word at the same time, you can search in the box with typing (allintitle: "monopulse" "polarization"), which is equel to use advance search with two key word in "key word 1" "key word 2", and select the for just the title, not fot whole paper.
![avatar](photos/google_scholar.png)