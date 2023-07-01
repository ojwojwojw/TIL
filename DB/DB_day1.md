```
CREATE TABLE contacts(
  name TEXT NOT NULL,
  age INTEGER NOT NULL,
  email TEXT NOT NULL UNIQUE
);

ALTER TABLE new_contacs RENAME TO new_contacs;

CREATE TABLE users(
  first_name TEXT NOT NULL,
  last_name TEXT NOT NULL,
  age INTEGER NOT NULL,
  country TEXT NOT NULL,
  phone TEXT NOT NULL,
  balance INTEGER NOT NULL
);


SELECT first_name , last_name , age , country , phone FROM users ;

SELECT first_name, age FROM users ORDER BY age ASC;
SELECT first_name ,age ,balance FROM users ORDER BY age, balance DESC;
SELECT first_name ,age ,balance FROM users ORDER BY balance DESC;

SELECT DISTINCT country FROM users;
SELECT DISTINCT first_name FROM users;
SELECT DISTINCT first_name,country FROM users;
SELECT DISTINCT first_name,country FROM users ORDER BY country;


SELECT first_name , age ,balance FROM users WHERE age >= 30 ;
SELECT first_name , age ,balance FROM users WHERE age >=30 and balance >= 500000 ;

SELECT first_name , age FROM users WHERE age LIKE '1%';
SELECT first_name , age FROM users WHERE age LIKE '영%';
SELECT first_name , age FROM users WHERE age LIKE '%도';
SELECT first_name , age FROM users WHERE age LIKE '%강원%';
SELECT first_name , age FROM users WHERE age LIKE '영_';
SELECT first_name , age FROM users WHERE age LIKE '_도';

SELECT first_name , last_name FROM users WHERE first_name LIKE '%호%';
SELECT first_name , last_name FROM users WHERE first_name LIKE '_준';

SELECT first_name , phone FROM users WHERE phone LIKE '02%';
SELECT first_name,age FROM users WHERE age LIKE '2_';
SELECT first_name , phone FROM users WHERE phone LIKE '%51_______';

SELECT first_name,country FROM users WHERE country IN ('경기도','강원도');
SELECT first_name,country FROM users WHERE country NOT IN ('경기도','강원도');

SELECT first_name,age FROM users WHERE age BETWEEN 20 AND 30;
SELECT first_name,age FROM users WHERE age >= 20 AND age <=30;
SELECT first_name,age FROM users WHERE age NOT BETWEEN 20 AND 30;
SELECT first_name,age FROM users WHERE age < 20 OR age > 30;

SELECT rowid, first_name FROM users LIMIT 10;

SELECT first_name, balance FROM users ORDER BY balance DESC LIMIT 10;
SELECT first_name, age FROM users ORDER BY age LIMIT 5;

SELECT rowid, first_name FROM users LIMIT 10 OFFSET 10;

SELECT first_name , last_name FROM users ;



DROP TABLE users;
```
