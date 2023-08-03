#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QVariant>
#include <QString>
#include <QTextStream>
#include <iostream>


enum Gender{Male = 0, Female = 1, Unknown = 2};

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);

private:
    QVariant first_name;
    QVariant last_name;
    QVariant age;
    QVariant address;
    QVariant city;
    QVariant country;
    QVariant phone_numer;
    Gender gender;


public:
    QVariant getFirst_name() const;

    void setFirst_name(const QVariant &newFirst_name);

    QVariant getLast_name() const;

    void setLast_name(const QVariant &newLast_name);

    QVariant getAge() const;

    void setAge(const QVariant &newAge);

    QVariant getAddress() const;

    void setAddress(const QVariant &newAddress);

    QVariant getCity() const;

    void setCity(const QVariant &newCity);

    QVariant getCountry() const;

    void setCountry(const QVariant &newCountry);

    QVariant getPhone_numer() const;

    void setPhone_numer(const QVariant &newPhone_numer);

    Gender getGender() const;

    void setGender(Gender newGender);

    friend std::ostream& operator <<(std::ostream& os, Person& p);


    Person(const QVariant &first_name, const QVariant &last_name, const QVariant &age, const QVariant &address, const QVariant &city, const QVariant &country, const QVariant &phone_numer, Gender gender);

    ~Person(){}

signals:

};

#endif // PERSON_H
