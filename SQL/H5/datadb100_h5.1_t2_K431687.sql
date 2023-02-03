-- Database basics 2021
-- H5.1 T2
-- anna.kleemola@tuni.fi

SELECT manufacturer_name
FROM manufacturer
WHERE country IN ('Finland', 'Italy')
ORDER BY manufacturer_name ASC;
