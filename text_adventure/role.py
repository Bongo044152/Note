import sys, random

def probability(p):
    if random.random() < p:
        return True # 事件發生
    else:
        return False # 事件未發生

class role_template:
    pass

class Monster:
    def __init__(self, Mtype):
        self.Mtype = Mtype
        self.df = 1
        if Mtype == "薛丁格的貓":
            self.hp = 5
            # 不死的概率
            self.probability = 0.51
        elif self.Mtype == "洪瑞君的貓":
            self.hp = 15
            self.atk = 2
            # 暴擊概率
            self.probability = 0.008

    def atkl(self, player):
        if self.Mtype == "薛丁格的貓":
            print(f"薛丁格的貓呼叫了薛丁格，薛丁格讓玩家進入量子態，你與{self.Mtype}發生了量子糾纏，雙方各50%概率死亡! ( 一生一死 )")
            if probability(0.5):
                print(f"{self.Mtype} 死亡... hp 歸 0")
                print(f"因為 薛丁格的貓 被觀測到死亡 ( 結果已經確定 )，所以無法復活...")
                self.probability = 0
                self.hp = 0
            else:
                player.hp = 0
        elif self.Mtype == "洪瑞君的貓":
            print(f"{self.Mtype} 看你不爽，使用爪子抓你一下! 喵!!!")
            if probability(self.probability):
                print("暴擊!!!! 5倍傷害! 無視防禦! 喵喵喵!")
                player.hp -= (self.atk * 5)
                print(f"造成了 {self.atk * 5} 點傷害!")
            else:
                atk = self.atk-player.df
                print(f"造成了 {atk} 點傷害!")
                player.hp -= atk
        print(f"你的血量目前剩餘 : {player.hp}")
        return player


class Player:
    def __init__(self, name, profession, hp, atk=2, df=1):
        self.name = name
        self.hp = hp
        self.atk = atk
        self.df = df
        self.profession = profession
        self.cd = 0
    def skill(self, enemies: list[Monster]) -> list[Monster]:
        if self.profession == "戰士":
            print(f"{self.name} 大吼一聲! 讓宇宙的 '商' 增加到最高，遊戲結束...")
            print("你與魔物同歸於盡...")
            sys.exit(-1)
        elif self.profession == "法師":
            print(f"{self.name} 吟唱著古老而晦澀的咒語，釋放了中子輻射，導致敵方的皮膚爛掉、多重器官衰竭，對手集體陣亡...")
            for i in range(len(enemies)):
                enemies[i].hp = 0
        else:
            print(f"{self.name} 使用了家族絕學，讓敵方隨機3名對手質量變成0，最後脫離了星球的引力控制，被甩飛了出去!!")
            for _ in range(min(len(enemies), 3)):
                target = random.choice(enemies)
                enemies.remove(target)
                print(f"\t{target.Mtype} 慘叫一聲，離開了這個世界")
        profession = self.profession
        if profession == "戰士":
            self.cd = 3
        elif profession == "法師":
            self.cd = 1
        else: # 刺客
            self.cd = 5
        return enemies
    def atkl(self, enemies: list[Monster]) -> list[Monster]:
        if self.profession == "法師":
            print(f"{self.name} 釋放出相對論性電子，放出超高的輻射線，讓隨機一名敵人直接死亡")
            target = random.choice(enemies)
            print(f"\t{target.Mtype} 來不及哀號，就死了..")
            index = enemies.index(target)
            enemies[index].hp = 0
        elif self.profession == "戰士":
            print(f"{self.name} 控制地球的引力，讓敵人的位能無條件到最大，並且轉換成旋轉動能，讓對手頭暈，所有對手的防禦降到0")
            for i in enemies:
                i.df = 0
        else:
            print(f"{self.name} 砍了一刀")
            print(f"{enemies[0].Mtype} 慘叫了一下!")
            atk = self.atk - enemies[0].df
            enemies[0].hp = enemies[0].hp - atk
            print(f"受到了 {atk} 點傷害!")
            print(f"{enemies[0].Mtype} 的血量變成 {enemies[0].hp}")
            if probability(0.5):
                print(f"{self.name} 觸發了職業技能: 吸血! 增加了 {atk} 點生命!")
                self.hp += atk
                print(f"當前生命值 : {self.hp}")

        return enemies
