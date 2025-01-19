from role import *
from tools import *
import os

def clear_screen():
    os.system('cls')

def wait_clear():
    input("Enter 已繼續 ... ")
    clear_screen()

t = 5
def behavior(enemies: list[Monster]):
    while True:
        chose = input("請選擇你本局的行為: (A) 普攻 (B) 大招 (C) 修整 : ").upper()
        print()
        if chose == 'A':
            return player.atkl(enemies)
        elif chose == 'B':
            if player.cd <= 0:
                return player.skill(enemies)
            else:
                print("技能冷卻中，無法啟動大招")
        elif chose == 'C':
            global t
            if t <= 0:
                print("修整次數已用完..")
                print("請重新選擇!")
                continue
            print(f"{player.name} 見時機不對，決定原地修整狀態")
            player.hp += 5
            print(f"血量回復 5 點! 目前血量{player.hp}")
            t -= 1
            print(f"修整次數剩餘 {t} 次")
            return enemies
        else:
            print("請重新選擇!")

def alife():
    # 薛丁格的貓 復活 !!
    index = 0

    while index < len(enemies):
        if enemies[index].Mtype == "薛丁格的貓" and enemies[index].hp <= 0:
            target = enemies[index]
            if probability(target.probability):
                print("-------------------------------------------------------")
                print(f"{target.Mtype}因為技能緣故，復活!")
                print("-------------------------------------------------------")
                target.hp = 5
                enemies[index] = target
        
        if enemies[index].hp <= 0:
            del enemies[index]
        else:
            index += 1

def monster_round(enemies: list[Monster]):

    alife()
    
    # 怪物回合
    for i in enemies:
        i.atkl(player)

def table():
    print("\n【怪物狀態表】")
    for i in enemies:
        print(f"\t{i.Mtype} 血量 : {i.hp}")
    print("\n【玩家狀態表】")
    print(f"\t角色名稱: {player.name}\n\t職業: {player.profession}\n\t血量: {player.hp}\n\t攻擊力: {player.atk}\n\t防禦力: {player.df}\n")


# 文字大冒險
clear_screen()

# 取名
print("歡迎來到 洪瑞君 的文字大冒險!")
player_name = input("冒險者，請輸入你的大名: ")

# 背景故事
input(f"{b_story}\t[enter 已繼續...]")
clear_screen()

# 選擇職業
print(role_intro)
player = chose_profession(player_name)
clear_screen()

# 進入遊戲
print(f"檢測到你選擇了職業\"{player.profession}\"")
if input("是否進入遊戲? [Y/n] ").upper() == 'N':
    print("離開遊戲")
else:
    x = 2
    level = 1
    enemies = generate_monster(level)
    print(f"難度指數 : {level}")
    while player.hp > 0:
        if x >= 1 and len(enemies) == 0:
            print("恭喜抵達下一關!")
            level += 1
            x -= 1
            enemies = generate_monster(level)
            print(f"難度指數 : {level}")
        elif x == 0 and len(enemies) == 0:
            break

        # 狀態追蹤
        table()

        # 你的回合
        enemies = behavior(enemies)
        print()
        # 敵方回合
        monster_round(enemies)

        player.cd -= 1

        wait_clear()
        alife()

    if player.hp > 0:
        print("恭喜你順利通關!")
    else:
        print("很遺憾，你失敗了")


    # 狀態追蹤
    table()