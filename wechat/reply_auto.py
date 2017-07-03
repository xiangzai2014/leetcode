#coding=utf8
import itchat
import time
import random
# 自动回复
# 封装好的装饰器，当接收到的消息是Text，即文字消息
@itchat.msg_register('Text')
@itchat.msg_register(['Map', 'Card', 'Note', 'Sharing', 'Picture', 'Video', 'Recording'])
def text_reply(msg):

    # 当消息不是由自己发出的时候
    if not msg['FromUserName'] == myUserName:
        # 发送一条提示给文件助手
        if 
        itchat.send_msg(u"[%s]收到好友@%s 的信息：%s\n" %
                        (time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(msg['CreateTime'])),
                         msg['User']['NickName'],
                         msg['Text']), 'filehelper')
        # 回复给好友
        '''
        num = random.randint(0,10)
        if (num % 10 == 1):
            num = num + 1
            return u'【自动回复】An apple a day keeps the doctor away\n 每天玩苹果手机，离博士学位越来越远。\n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 2):
            num = num + 1
            return u'【自动回复】在兵荒马乱的年纪里 很高兴认识你 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 3):
            num = num + 1
            return u'【自动回复】深化浅说 长路慢走 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 3):
            num = num + 1
            return u'【自动回复】你一牵我舞如飞 你一引我懂进退 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 4):
            num = num + 1
            return u'【自动回复】初识之作乍见之欢  日后惊于久处不厌 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 5):
            num = num + 1
            return u'【自动回复】我相信有一天 我会听到马蹄溅起落花的声音 如酥的细雨会打湿我的肩头 你会裹着风雪 穿过万水千山 来到我面前 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 6):
            num = num + 1
            return u'【自动回复】I wish to wish the wish you wish to wish, but if you wish the wish the witch wishes, I won’t wish the wish you wish to wish. 😉 \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 7):
            num = num + 1
            return u'【自动回复】人生就像服务器，宕机，断网，没有指定版本软件包，找不到对象才是常态。。。看别人的文档永远配不好自己的环境，遇到绕不过去的坑那就只能踩平了～ \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 8):
            num = num + 1
            return u'【自动回复】泰戈尔曾说：“静止便是死亡，只有运动才能敲开永生的大门。” \n已经收到您的的信息：%s\n' % (msg['Text'])
        elif (num % 10 == 9):
            num = num + 1
            return u'【自动回复】好看的皮囊千篇一律，有趣的灵魂万里挑一 \n已经收到您的的信息：%s\n' % (msg['Text'])
        else:
            num = num + 1
            return u'【自动回复】"日暮提回一筐月，江心钓得半篓风”，“识君应我幸，何故恨相逢" \n已经收到您的的信息：%s\n' % (msg['Text'])
        '''
        return u'测试~\n已经收到您的的信息：%s\n' % (msg['Text'])
    else:
        return u'【自动回复】您好，我现在正在睡觉，等我睡醒了再说。\n已经收到您的的信息：%s\n' % (msg['Text'])

if __name__ == '__main__':

    itchat.auto_login()
    # 获取自己的UserName
    #myUserName = itchat.get_friends(update=True)[0]["UserName"]
    myUserName = itchat.get_friends(update=True)[0]["UserName"]
    itchat.run()
