
import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import binom, poisson, norm

plt.rcParams['font.sans-serif'] = ['SimHei']  # 使其表格能正常显示中文
plt.rcParams['axes.unicode_minus'] = False  # 解决负号显示问题


def plot_distributions(sample_size=5000):  # 样本容量设为5000
    uniform_data = np.random.uniform(0, 1, sample_size)  # 均匀分布U(0,1)
    binomial_data = np.random.binomial(100, 0.5, sample_size)  # 二项分布B(100,0.5)
    poisson_data = np.random.poisson(50, sample_size)  # 泊松分布 π（50）
    normal_data = np.random.normal(0, 1, sample_size)  # 标准正态分布 N(0,1)

    fig, axs = plt.subplots(2, 2, figsize=(12, 10))

    # 均匀分布U(0,1)
    axs[0, 0].hist(uniform_data, bins=50, density=True, alpha=0.7)
    axs[0, 0].set_title(
        f"一、均匀分布U(0,1)\n均值: {np.mean(uniform_data):.4f},中位数: {np.median(uniform_data):.2f},方差: {np.var(uniform_data):.4f}")
    x = np.linspace(0, 1, 5000)
    axs[0, 0].plot(x, np.ones_like(x), 'r--', label="理论分布")

    # 二项分布B(100,0.5)
    axs[0, 1].hist(binomial_data, bins=np.arange(0, 101)-0.5, density=True, alpha=0.7)
    axs[0, 1].set_title(
        f"二、二项分布B(100,0.5)\n均值: {np.mean(binomial_data):.4f},中位数: {np.median(binomial_data):.2f},方差: {np.var(binomial_data):.4f}")
    x = np.arange(0, 100)
    axs[0, 1].plot(x, binom.pmf(x, 100, 0.5), 'r--', label="理论分布")

    # 泊松分布 π（50）
    axs[1, 0].hist(poisson_data, bins=np.arange(0, max(poisson_data) + 1)-0.5, density=True, alpha=0.7)
    axs[1, 0].set_title(
        f"三、泊松分布 π（50）\n均值: {np.mean(poisson_data):.4f},中位数: {np.median(poisson_data):.2f},方差: {np.var(poisson_data):.4f}")
    x = np.arange(0, max(poisson_data) + 1)
    axs[1, 0].plot(x, poisson.pmf(x, 50), 'r--', label="理论分布")

    # 标准正态分布 N(0,1)
    axs[1, 1].hist(normal_data, bins=50, density=True, alpha=0.7)
    axs[1, 1].set_title(
        f"四、正态分布 N(0,1)\n均值: {np.mean(normal_data):.4f},中位数: {np.median(normal_data):.4f},方差: {np.var(normal_data):.4f}")
    x = np.linspace(-5, 5, 5000)
    axs[1, 1].plot(x, norm.pdf(x, 0, 1), 'r--', label="理论分布")

    plt.suptitle("四种不同的分布")
    plt.tight_layout()
    plt.show()


plot_distributions()
