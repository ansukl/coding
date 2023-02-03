-- Database basics 2021
-- H6 T7
-- anna.kleemola@tuni.fi

SELECT ice_cream_name, manufacturing_cost
FROM ice_cream
WHERE manufacturing_cost = (SELECT MAX(manufacturing_cost) FROM ice_cream);
