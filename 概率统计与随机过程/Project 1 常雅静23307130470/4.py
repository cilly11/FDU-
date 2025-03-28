import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
plt.rcParams['font.sans-serif'] = ['SimHei'] # 使其表格能正常显示中文
def central_limit_theorem(sample_size=100, vector_count=1000):
    # 生成多个均匀分布的随机数并求和
    uniform_sums = np.sum(np.random.uniform(0, 1, (vector_count, sample_size)), axis=1)
    # 生成一个1000×100的矩阵，对每一行进行求和，即得到样本数
    plt.hist(uniform_sums, bins=50, density=True, alpha=0.7, label="Sum of Uniform Distributions")
    # bins=50 设置直方图的柱子数量，density=True 使得直方图的总面积为1，alpha=0.7 设置透明度，
    mean_sum = np.mean(uniform_sums)
    std_sum = np.std(uniform_sums)
    x = np.linspace(mean_sum - 4 * std_sum, mean_sum + 4 * std_sum, 1000)
    plt.plot(x, norm.pdf(x, mean_sum, std_sum), label="正态分布", linestyle="dashed")

    plt.title("中心极限定理CLT")
    plt.xlabel("服从均匀分布的随机变量之和")
    plt.ylabel("概率")
    plt.legend()
    plt.show()


central_limit_theorem()
