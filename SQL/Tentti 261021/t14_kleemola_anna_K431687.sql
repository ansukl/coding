-- T1.4
-- Kleemola Anna, K431687

SELECT wine.name AS name1, w.name AS name2
FROM wine LEFT OUTER JOIN served_with sw
    ON  wine.wine_id = sw.wine_id
    LEFT OUTER JOIN wine w
        ON wine.wine_id = w.wine_id
            LEFT OUTER JOIN served_with s_with
            ON w.wine_id = s_with.wine_id
WHERE wine.wine_id != w.wine_id AND sw.food_id = s_with.food_id
ORDER BY name1 ASC, name2 ASC;
