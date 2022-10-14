import re
from sys import argv, exit
import requests


def main():
    print("\n\t\t**** CURRENCY CONVERTER ****")
    if len(argv) > 1 and argv[1].lower().strip() == "rates":
        print(show_currencies("https://api.exchangerate-api.com/v4/latest/USD"))
    else:
        pass

    from_curr = input("\nConvert from: ").strip().upper()
    to_curr = input("Convert to: ").strip().upper()
    amount = numbers_only((input("\nAmount: ")))
    amount = float(amount)

    print(output(from_curr, to_curr, amount))


def show_currencies(url):
    data = requests.get(url).json()
    currencies = data["rates"]
    return currencies


def convert(from_currency, to_currency, amount):
    url = "https://api.exchangerate-api.com/v4/latest/USD"

    if from_currency != "USD":
        amount = amount / requests.get(url).json()["rates"][from_currency]

    amount = round(amount * requests.get(url).json()["rates"][to_currency], 4)
    return amount


def output(from_curr, to_curr, amount):
    try:
        converted_amount = convert(from_curr, to_curr, amount)
        converted_amount = round(converted_amount, 2)
        converted_amount = str(converted_amount)
        return f"{amount} {from_curr} is equivalent to {converted_amount} {to_curr}"
    except KeyError:
        exit("Please enter valid currency")


def numbers_only(string):
    regex = re.compile(r"^([0-9]{1,3}[,]?)*(.[0-9]+)?$")

    if result := regex.match(string):
        return string.replace(",", "")
    raise exit("Please enter a numeric Value")


if __name__ == "__main__":
    main()
