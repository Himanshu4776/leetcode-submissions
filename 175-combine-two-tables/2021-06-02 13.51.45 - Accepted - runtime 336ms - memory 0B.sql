# Write your MySQL query statement below
select Person.FirstName, Person.LastName, Address.City, Address.State from Person left join Address on Address.personId = Person.personId;
