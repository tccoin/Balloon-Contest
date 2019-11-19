# -*- coding: UTF-8 -*-
# 白学生成器


class White():

    def __init__(self, isHappy, reason):
        self.isHappy = isHappy
        self.reason = reason

    def __add__(self, that):
        if self.isHappy and that.isHappy:
            return White(False, '第一次有了{}，又有了{}。但是，为什么…'.format(self.reason, that.reason))

    def why(self):
        print(self.reason)


happy1 = White(True, '喜欢的语言')
happy2 = White(True, '全世界最好的语言')
double_happy = happy1 + happy2
double_happy.why()  # '第一次有了喜欢的语言，又有了全世界最好的语言。但是，为什么…'
