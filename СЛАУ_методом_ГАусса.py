import numpy as np

def gaussian_elimination(a, b):
    n = len(b)
    
    # Прямой ход
    for i in range(n):
        # Нормализация текущей строки
        for j in range(i + 1, n):
            factor = a[j][i] / a[i][i]
            a[j] = a[j] - factor * a[i]
            b[j] = b[j] - factor * b[i]

    # Обратный ход
    x = np.zeros(n)
    for i in range(n - 1, -1, -1):
        x[i] = (b[i] - np.dot(a[i, i + 1:], x[i + 1:])) / a[i][i]

    return x

# Пример использования
A = np.array([[3, 2, -4],
              [2, 3, 3],
              [5, -3, 1]], dtype=float)

B = np.array([3, 15, 14], dtype=float)

solution = gaussian_elimination(A, B)
print("Решение:", solution)
