#!/bin/bash

random_number=$((1+$RANDOM%10))

while true; do
  read -p "Введите ваше число: " user_number

  if ! [[ "$user_number" =~ ^[0-9]+$ ]]; then
    echo "Введите число"
    continue
  fi

  if [ $user_number -eq $random_number ]; then
    echo "Вы угадали!"
    break
  else
    echo "Ещё раз"
  fi
done

exit 0
