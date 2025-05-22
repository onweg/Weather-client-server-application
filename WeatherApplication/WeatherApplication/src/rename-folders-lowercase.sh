#!/bin/bash

# Проверяем, передан ли аргумент или используем текущую директорию
TARGET_DIR="${1:-.}"

echo "Начинаем обработку с директории: $TARGET_DIR"

# Используем find с сортировкой по убыванию глубины (-depth), чтобы сначала обрабатывать самые вложенные папки
find "$TARGET_DIR" -depth -type d | while IFS= read -r folder; do
    # Пропускаем текущую директорию (.)
    if [[ "$folder" == "$TARGET_DIR" ]]; then
        continue
    fi

    # Получаем имя родителя и базовое имя папки
    parent_dir="$(dirname "$folder")"
    base_name="$(basename "$folder")"
    
    # Приводим имя к нижнему регистру
    lower_name="$(echo "$base_name" | tr '[:upper:]' '[:lower:]')"
    new_path="$parent_dir/$lower_name"

    # Если имя уже в нижнем регистре — пропускаем
    if [[ "$folder" == "$new_path" ]]; then
        continue
    fi

    # Переименовываем папку
    if mv "$folder" "$new_path"; then
        echo "Переименовано: $folder -> $new_path"
    else
        echo "Ошибка при переименовании: $folder"
    fi
done
