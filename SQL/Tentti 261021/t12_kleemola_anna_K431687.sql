-- T1.2
-- Kleemola Anna, K431687

SELECT name
FROM wine
WHERE wine_id IN
    (SELECT wine_id FROM served_with WHERE food_id = 1)
    AND
    wine_id NOT IN
    (SELECT  wine_id FROM served_with WHERE food_id = 2)
ORDER BY name ASC;
