# airlinereservation-OOP
Its a simple project in oop that demonstrates the major concepts of oop in c++ like polymorphism(virtual functions),Filing(Object),Inheritance etc.
Using this application you can reserve,delete,update customer seats.
Filing is used for the persistance of data.
In Filing(binary) data is stored,retrived,updated or deleted in the form of objects.
Whenever a customer record is deleted a temporary file is created in which all the data is copied that is in main data file except the customer whose data
is to be deleted now the main file contains only that person whose record is to be deleted so that person record is deleted by making the main data file empty 
and after the data from temp file is copied to the main file data and the updated record is shown to the user.
Same technique is used for data upgradation.
