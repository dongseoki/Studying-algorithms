# 259
class Human : 
    def __init__(self, name, age, sex):
        self.name = name
        self.age = age
        self.sex = sex

    def setInfo(self, name, age, sex):
        self.name = name
        self.age = age
        self.sex = sex
    
    def __del__(self):
        print("나의 죽음을 적에게 알리지 말라")

    def who(self):
        print("이름 : {}, 나이: {}, 성별: {}".format(self.name,self.age,self.sex))
h1 = Human("아름","25","여자")
h1.setInfo("tqf","2222","무성")
h1.who()



h2 = Human("아름","25","여자")

print('-------')
del h1
del h2