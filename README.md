# Потоки, синхронизация и алгоритм банкира

![Стек](https://img.shields.io/badge/C%2B%2B20%20%C2%B7%20Threads-334155?style=flat-square) ![Семестр](https://img.shields.io/badge/семестр-3-0f766e?style=flat-square) ![Статус](https://img.shields.io/badge/статус-%D0%A3%D1%87%D0%B5%D0%B1%D0%BD%D1%8B%D0%B9%20%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82-64748b?style=flat-square)

Лабораторная №4: сравнение механизмов синхронизации, параллельная обработка данных и поиск безопасной последовательности выделения ресурсов.

## Программы

| Файл | Задача |
|---|---|
| [main1.cpp](main1.cpp) | Мьютекс, семафор, барьер, атомарные операции и замеры времени |
| [main2.cpp](main2.cpp) | Последовательная и многопоточная обработка товаров с регулярными выражениями |
| [main3.cpp](main3.cpp) | Алгоритм банкира: ресурсы, потребности и безопасная последовательность |

## Сборка и запуск

Нужен компилятор и стандартная библиотека с поддержкой C++20, включая `<semaphore>` и `<barrier>`.

```bash
c++ -std=c++20 -pthread main1.cpp -o synchronization
./synchronization

c++ -std=c++20 -pthread main2.cpp -o parallel_processing
./parallel_processing

c++ -std=c++20 main3.cpp -o banker
./banker
```

## Материалы

Исходные заметки по сборке: [compilation](compilation). Отчёт находится в [архиве лабораторной](https://github.com/Assweg/nstu).

---

[Каталог учебных репозиториев](https://github.com/Assweg/nstu) · [Профиль Assweg](https://github.com/Assweg)

## Материалы из локальной папки

Исходники и документы этой работы собраны в этом репозитории.

Локальный вариант отличается от ранее опубликованного кода и сохранён в [local-version](local-version/). Основная версия остаётся в корне. Для запуска локального варианта сначала перейдите в его каталог.

[local-version](local-version/)

### Отчёты и документы

- [Отчет лаба 4 Бутаков НМ.docx](local-version/%D0%9E%D1%82%D1%87%D0%B5%D1%82%20%D0%BB%D0%B0%D0%B1%D0%B0%204%20%D0%91%D1%83%D1%82%D0%B0%D0%BA%D0%BE%D0%B2%20%D0%9D%D0%9C.docx)
