-- T1.3
-- Kleemola Anna, K431687

SELECT food.food_id, food.name, COUNT(sw.wine_id) AS no_wines, MIN(price) AS cheapest_price, COUNT(DISTINCT(producer_id)) AS no_producers
FROM food LEFT OUTER JOIN served_with sw
    ON food.food_id = sw.food_id
    LEFT OUTER JOIN wine
        ON sw.wine_id = wine.wine_id
GROUP BY food.name
ORDER BY food.food_id ASC;
