#include "person.h"

Person::Person(QObject *parent)
    : QObject{parent}{}

Person::Person(const QVariant &first_name
               , const QVariant &last_name
               , const QVariant &age
               , const QVariant &address
               , const QVariant &city
               , const QVariant &country
               , const QVariant &phone_numer
               , Gender gender)
    : first_name(first_name),
    last_name(last_name),
    age(age),
    address(address),
    city(city),
    country(country),
    phone_numer(phone_numer),
    gender(gender){}

QVariant get_gender(Gender g) {
    switch (g) {
    case 0:
        return QVariant("Male");
    case 1:
        return QVariant("Female");
    case 2:
        return QVariant("Unknown");
    default:
        return QVariant("Unknown");
    }
}

std::ostream& operator <<(std::ostream& os, Person& p)
{
    os << "First Name: " << p.getFirst_name().toString().toStdString() << " | "
       << "Last Name: " << p.getLast_name().toString().toStdString() << " | "
       << "Age: " << p.getAge().toInt() << "\n"
       << "Address: " << p.getAddress().toString().toStdString() << "\n"
       << "City: " << p.getCity().toString().toStdString() << " | "
       << "Country: " << p.getCountry().toString().toStdString() << "\n"
       << "Phone Number: " << p.getPhone_numer().toString().toStdString() << " | "
       << "Gender: " << get_gender(p.getGender()).toString().toStdString() << "\n_______________________________________________\n\n";
    os.flush();

    return os;
}


QVariant Person::getFirst_name() const
{
    return first_name;
}

void Person::setFirst_name(const QVariant &newFirst_name)
{
    first_name = newFirst_name;
}

QVariant Person::getLast_name() const
{
    return last_name;
}

void Person::setLast_name(const QVariant &newLast_name)
{
    last_name = newLast_name;
}

QVariant Person::getAge() const
{
    return age;
}

void Person::setAge(const QVariant &newAge)
{
    age = newAge;
}

QVariant Person::getAddress() const
{
    return address;
}

void Person::setAddress(const QVariant &newAddress)
{
    address = newAddress;
}

QVariant Person::getCity() const
{
    return city;
}

void Person::setCity(const QVariant &newCity)
{
    city = newCity;
}

QVariant Person::getCountry() const
{
    return country;
}

void Person::setCountry(const QVariant &newCountry)
{
    country = newCountry;
}

QVariant Person::getPhone_numer() const
{
    return phone_numer;
}

void Person::setPhone_numer(const QVariant &newPhone_numer)
{
    phone_numer = newPhone_numer;
}

Gender Person::getGender() const
{
    return gender;
}

void Person::setGender(Gender newGender)
{
    gender = newGender;
}
