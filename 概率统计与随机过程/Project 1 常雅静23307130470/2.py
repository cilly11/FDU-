import numpy as np

def bombing_probability(trials=10000, x_axis=120, y_axis=80):
    inside_count = 0
    for _ in range(trials):
        x = np.random.normal(0, 60)
        y = np.random.normal(0, 40)

        if (x ** 2 / x_axis ** 2 + y ** 2 / y_axis ** 2) <= 1:
            inside_count += 1

    probability = inside_count / trials
    print(f"每颗炮弹落在椭圆形区域的概率: {probability:.6f}")


bombing_probability()
