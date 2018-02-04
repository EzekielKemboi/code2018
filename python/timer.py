import time

class Timer:
    def __init__(self):
        self.unit=["年","月","天","小时","分钟","秒"]
        self.lasted=[]
        self.prompt="未开始计时"
        self.begin=0
        self.end=0

    def start(self):
        if self.begin!=0:
            print("已经开始了")
        else:
            self.begin=time.localtime()
            print("计时开始")

    def stop(self):
        if self.begin!=0:
            self.end=time.localtime()
            self.calc()
            print("计时结束")
        else:
            print("还没有开始计时")

    def calc(self):
        self.prompt="总共运行了"
        for index in range(6):
            self.lasted.append(self.end[index]-self.begin[index])
            self.prompt+=(str(self.lasted[index])+self.unit[index])
        self.begin=0
        self.end=0

    def __add__(self,other):
        prompt="总共时间为"
        result=[]
        for index in range(6):
            result.append(self.lasted[index]+other.lasted[index])
            prompt+=(str(result[index])+self.unit[index])
        return prompt

    def __repr__(self):
        return self.prompt

while 1:    
    t=Timer()
    t.start()
    while input()!='l':
        pass
    t.stop()
    print(t)


            
