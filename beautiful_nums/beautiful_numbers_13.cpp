#include <iostream>
#include <cmath>

//Тестовое задание.
//В данной задаче будут рассматриваться 13-ти значные числа в тринадцатиричной системе исчисления(цифры 0,1,2,3,4,5,6,7,8,9,A,B,C) с ведущими нулями.
//Например, ABA98859978C0, 6789110551234, 0000007000000
//Назовем число красивым, если сумма его первых шести цифр равна сумме шести последних цифр.


//идея: работать с этими числами как с суммами от 0 до 12*6 слева от середины,
//и считать сколько чисел имеют сумму х слева и справа в лупе от 0 до 12*6


//Идея 2.0 - использовать динамическое программирование. Постепенно считать варианты начиная с суммы одного и
//сохранять их в map P.S пошел другим путем.




// return (-1)^k
int minus_one_pow_k(int x) {
    if (x % 2 == 0)
        return 1;
    else
        return -1;
};


// Биномиальный коэффициент
long int nCk(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return nCk(n - 1, k - 1) + nCk(n - 1, k);
}


// Здесь я использую данную функцию для подсчета количества всех возможных сум {sum} из 6-и чисел слева:
// https://disk.yandex.ru/i/4nerTmv8SiIRtw
// используя принцип включений-исключений можно посчитать, сколько чисел может быть образовано
int quantitySummands(int sum, int base, int length_on_side) {

    int n = length_on_side;
    int r_limit = base - 1;
    int quantity = 0;
    int upper_equation_limit = std::floor(sum / (r_limit + 1));

    for (int k = 0; k <= upper_equation_limit; k++) {
        quantity += minus_one_pow_k(k) * nCk(n, k) * nCk(sum - k * (r_limit + 1) + n - 1, n - 1);
    }
    return quantity;
}


unsigned __int64 howManyWays(int sum, int base, int numbers_in_centre, int length_on_side) {
    unsigned __int64 ways;

    // считается количество сумм из {length_on_side} цифр
    ways = quantitySummands(sum, base, length_on_side);

    // для каждого числа слева существует число {ways} вариантов, когда слева и справа сумма равна {sum}
    // поэтому возводим ways во вторую степень и получаем число вариантов без учета серединных чисел
    ways = ways * ways;

    // умножаем на base^numbers_in_centre, т.к. серединные числа добавляют варианты
    return ways * (pow(base, numbers_in_centre));
}

unsigned __int64 beautifulNumbers(int base, int numbers_in_centre, int length_on_side) {
    unsigned __int64 quantity = 0;
    unsigned __int64 add;
    // maxSum это наша максимально возможная сумма из {length_on_side} цифр
    const int maxSum = (base - 1) * length_on_side;

    for (int i = 0; i <= maxSum; i++) {
        std::cout << i;
        add = howManyWays(i, base, numbers_in_centre, length_on_side);
        std::cout << ": " << add << std::endl;
        quantity += add;

    }

    std::cout << std::endl;
    std::cout << "Ответ: ";

    return quantity;
}

// Данная программа работает не только с заданными в задаче числами, но и с пользовательскими вариантами.
// P.S пользовательский вариант может показывать неверный ответ, если он вынуждает программу преодолеть лимит __int64

int main() {
    // Система исчисления
    int base = 13;
    // Кол-во чисел в центре
    int numbers_in_centre = 1;
    // Кол-во чисел по бокам
    int length_on_side = 6;

    std::cout << "Введите систему исчесления: ";
    std::cin >> base;
    std::cout << "\n\n";

    std::cout << "Введите кол-во чисел посередине: ";
    std::cin >> numbers_in_centre;
    std::cout << "\n\n";

    std::cout << "Введите кол-во чисел по бокам: ";
    std::cin >> length_on_side;
    std::cout << "\n\n";

    std::cout << beautifulNumbers(base, numbers_in_centre, length_on_side);

    return 0;
}
