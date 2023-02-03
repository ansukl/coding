-- T1.1
-- Kleemola Anna, K431687

SELECT type, wine.name, price, producer.name
FROM wine LEFT OUTER JOIN producer
    ON wine.producer_id = producer.producer_id
WHERE (type = 'white wine' OR type = 'red wine') AND price NOT NULL
ORDER BY type ASC, wine.name ASC;
