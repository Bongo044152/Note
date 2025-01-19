import random

b_story = '''
在遙遠的王國──「艾爾羅德」，傳說中隱藏著一個神秘的力量，能賦予持有者無限的權力。這股力量來自於一顆古老的水晶，名為「光輝之心」，它被封印在位於王國最深處的古老迷宮中。這迷宮無數次吞噬了前來尋找寶藏和力量的冒險者，至今無人能夠突破。

你，一名年輕的冒險者，懷著對未知的渴望和對力量的追求，決定踏上這條危險的道路。你曾聽過這顆水晶的傳說，也知道要突破迷宮，必須面對種種恐怖的挑戰與考驗。傳言中，迷宮不僅充滿著陷阱和怪物，還有許多心靈上的試煉，只有真正勇敢且有智慧的冒險者，才能找到「光輝之心」的所在。

你決心將這一切交給命運，帶著堅定的信念與準備，開始了這場關乎生死的冒險。每一步都可能是最後一步，每一個選擇都可能決定你是否能繼續前進。洞穴深處的黑暗似乎在嘲笑你的膽怯，但你無所畏懼，踏進了那扇沉重的古老大門。

眼前的世界仿佛瞬間變得陌生而危險，空氣中彷彿充滿了謎團與危機。你不知道將會面對什麼，但你知道，這場冒險已經無法回頭，而唯一能做的，就是向前邁進...
'''

character_data = {
    "法師": {"hp": 15, "atk": 1, "df": 1},
    "戰士": {"hp": 25, "atk": 0, "df": 2},
    "刺客": {"hp": 15, "atk": 7, "df": 1}
}


role_intro = role_intro = f'''
【職業介紹】

1. 戰士
背景故事： 戰士來自於艾爾羅德的古老戰士家族，擁有強大的體魄和決不屈服的意志。他們的目標是將所有威脅從這片土地上清除，無論面對何種強敵。戰士訓練有素，能夠駕馭無與倫比的力量，並且在困境中能保持冷靜。在戰場上，他們如同一座不可撼動的堡壘，無懼任何攻擊。

技能：
技能名稱：商增定律
讓宇宙中的 '商' 增加，達到毀滅宇宙的效果!
普通攻擊：
透過自身強硬的素質，改變周圍的引力場，造成控制效果

血量: {character_data["戰士"]["hp"]}
攻擊: {character_data["戰士"]["atk"]} ( 不具意義 )
防禦值: {character_data["戰士"]["df"]}

2. 法師
背景故事： 法師來自於艾爾羅德最著名的學術殿堂，他們掌握著古老且深奧的魔法，擁有讓人難以置信的力量。這些智者深知，只有透過知識和智慧才能達到真正的力量。他們的咒語強大且致命，能瞬間改變戰局。然而，法師也有一個致命的弱點，那就是他們的體力極其脆弱，若不謹慎，可能會在戰鬥中倒下。

技能：
技能名稱：中子輻射
釋放強力的中子輻射，瞬間摧毀目標的皮膚，導致對方多重器官衰竭，對所有敵人造成致命傷害。
普通攻擊：
釋放出相對論性電子，放出超高的輻射線，讓隨機一名敵人直接死亡

血量: {character_data["法師"]["hp"]}
攻擊: {character_data["法師"]["atk"]} ( 不具意義 )
防禦值: {character_data["法師"]["df"]}

3. 刺客
背景故事： 刺客來自於艾爾羅德的暗影公會，他們以隱秘的行動和致命的暗殺技巧聞名。刺客不依賴強大的武器或盔甲，而是依靠敏捷的身手和卓越的計謀，悄無聲息地消除目標。刺客的目標不是正面交鋒，而是利用速度和技巧，在敵人不注意時發起致命一擊。只要一擊命中，敵人往往無法逃脫。

技能：
技能名稱：??? ( 家族絕學 )
隨機讓3名敵人質量歸0
普通攻擊：
砍你一刀! 傷害 : 7 ( 50% 概率吸血 )

血量: {character_data["刺客"]["hp"]}
攻擊: {character_data["刺客"]["atk"]}
防禦值: {character_data["刺客"]["df"]}

'''

from role import Player
def chose_profession(name):
    while True:
        chose = input("選擇你的職業 (A) 法師 (B) 戰士 (C) 刺客 : ").upper()

        if chose == 'A':
            data = character_data["法師"]
            return Player(name, "法師", data["hp"], data["atk"], data["df"])
        elif chose == 'B':
            data = character_data["戰士"]
            return Player(name, "戰士", data["hp"], data["atk"], data["df"])
        elif chose == 'C':
            data = character_data["刺客"]
            return Player(name, "刺客", data["hp"], data["atk"], data["df"])
        else:
            print("錯誤的輸入，請重新選擇")

from role import Monster
def generate_monster(level: int) -> list[Monster]:
    if level == 1:
        num_of_cat1 = random.randint(2, 5) # 洪瑞君的貓
        num_of_cat2 = 0 # 薛丁格的貓
    elif level == 2:
        num_of_cat1 = random.randint(5, 7) # 洪瑞君的貓
        num_of_cat2 = random.randint(1,2) # 薛丁格的貓
    elif level == 3:
        num_of_cat1 = random.randint(7, 15) # 洪瑞君的貓
        num_of_cat2 = random.randint(4,5) # 薛丁格的貓

    enemies = []
    for _ in range(num_of_cat1):
        enemies.append(Monster("洪瑞君的貓"))
    for _ in range(num_of_cat2):
        enemies.append(Monster("薛丁格的貓"))

    random.shuffle(enemies)
    return enemies