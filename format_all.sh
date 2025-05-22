#!/bin/bash

# Проверяем наличие clang-format
if ! command -v clang-format &> /dev/null
then
    echo "clang-format не установлен. Пожалуйста, установи его."
    exit 1
fi

# Рекурсивно ищем .cpp и .h файлы и форматируем их
find . \( -name "*.cpp" -o -name "*.h" \) -print0 | while IFS= read -r -d '' file
do
    echo "Форматируем $file"
    clang-format -i "$file"
done

echo "Форматирование завершено!"
