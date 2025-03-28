import numpy as np
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm

plt.rcParams['font.sans-serif'] = ['SimHei'] # 使其表格能正常显示中文
#plt.rcParams['axes.unicode_minus'] = False # 解决负号现实问题
def birthday_problem_simulation(trials=50000, max_n=50): # 模拟次数设为10000，最大人数为50
    probabilities = []
    for n in range(1, max_n + 1):
        matches = 0
        # 人数为n时具有相同生日的实验次数
        for _ in range(trials):
            birthdays = np.random.randint(1, 365, n)
            # 一年按365天来计算
            if len(birthdays) != len(set(birthdays)):
                # 判断是否存在相同的生日
                matches += 1
        probabilities.append(matches / trials)


    plt.plot(range(1, max_n + 1), probabilities, label="Monte Carlo Probability")
    key_points_x = [10, 20, 30, 40, 50] # 关键点
    key_points_y = [probabilities[x - 1] for x in key_points_x]
    for x, y in zip(key_points_x, key_points_y):
        plt.scatter(x,y,color='black') # 标记关键点
        plt.annotate(f"({x}, {y:.5f})", (x, y), textcoords="offset points", xytext=(0, 5), ha='center')

    plt.xlabel("人数")
    plt.ylabel("相同生日的可能性")
    plt.title("生日问题——使用Monte Carlo方法计算至少两个人生日相同的概率")
    plt.legend()
    plt.show()

birthday_problem_simulation()
