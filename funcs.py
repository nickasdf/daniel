
def entering(a):
    text = []
    for i in range(a):
        text.append(input("Введіть рядок: "))
    return text


def output_text(text):
    for i in text:
        print(i)


def count_words(text, a):
    for i in range(a):
        line = text[i]
        line = fun(line)
        text[i] = line
    return text


def fun(fragment):
    if fragment.count("{") > 0:
        new_fragment = fragment[fragment.find("{") + 1:fragment.rfind("}")]
        new_fragment = fun(new_fragment)
        count = fragment.count("{") - 1
        fragment = fragment[:fragment.find("{") + 1] + new_fragment + " ;" + str(len(new_fragment.split()) - count) + fragment[fragment.rfind("}"):]

    return fragment
