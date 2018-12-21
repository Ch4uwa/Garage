# Garage
School project, garage with abstract vehicle class, some attributes per vehicle.
Remove, add, printall, printtypes.



## Kravspecifikation
En samling av fordon:
Det ska finnas en funktion ListVehicles som listar samtliga fordon i garaget
Det ska finnas en funktion ListTypeOfVehicles som listar samtliga olika typer av fordon i garaget och hur många av dessa som står i garaget
Det ska finnas en funktion AddVehicle som lägger till ett fordon ur garaget
Det ska finnas en funktion RemoveVehicle som tar bort fordon ur garaget
Ha en max-gräns som krävs som inparameter vid instansieringen av ett nytt garage
Det ska finnas en funktion SearchVehicle som söker efter ett specifikt fordon via 
REG-NR och skriver ut det om det finns, annars inte.
Möjlighet att söka efter ett flertal fordon på ett flertal valfria variabler.
Olika fordon, Klassen Vehicle och dess ärvande subklasser
Vehicle innehåller samtliga variabler som ska finnas i samtliga fordonstyper.
EX. REG-NR, Färg, Antal hjul. Och andra variabler ni kan komma på.
Det måste minst finnas följande subklasser:
Bicycle
Motorcycle
Car
Bus
Truck
Dessa skall innehålla minst två egna attribut
Ett textbaserat UI för en konsolapplikation
Det skall gå att navigera till SAMTLIG funktionalitet från garage via UI:t
Det skall gå att SKAPA ett Garage i UI:t.
Det skall gå att stänga av applikationen från UI:t
