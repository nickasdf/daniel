
import funcs

a = int(input("Введіть кількість рядків: "))
text = funcs.entering(a)
text = funcs.count_words(text, a)
funcs.output_text(text)
