-- Database basics 2021
-- H1 T5
-- anna.kleemola@tuni.fi
SELECT name, price
FROM tea
WHERE price >= '6.00' 
ORDER BY price DESC, name ASC;