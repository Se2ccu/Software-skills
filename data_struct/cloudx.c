
int update(St *vbear)
{
    /* 可以选择放到chr上报判断 */
    if (userSeviceTypeSupport) {
        vbear->isChrNextFrame = false;
        return;
    }

    now = state;

    /* 帧识别开关一定开 */
    if (last == act && now == inact) {
        vbear->isChrNextFrame = true;
    }

    last = now;
}

if (flag = 1 && rlcAgent == ACTIVE) {
    vbear->isChrNextFrame = false;
    return;
}


if (!vbear->isChrNextFrame) {
    extchr()
    vbear->isChrNextFrame = false;
}