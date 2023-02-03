-- Database basics 2021
-- H5.2 T1
-- anna.kleemola@tuni.fi

SELECT COUNT(ice_cream_id) AS ice_cream_count,
    MIN(manufacturing_cost) AS min_cost,
    MAX(manufacturing_cost) AS max_cost
FROM ice_cream;
