# Brainfuck -> Mindopen converter

SET="\+\-\>\<\[\]\.\,"
cat $1 | tr -dc $SET | tr $SET "asrlocdi"
