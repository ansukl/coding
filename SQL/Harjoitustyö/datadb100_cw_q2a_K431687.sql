-- Database basics 2021
-- Course work, Query 2A
-- anna.kleemola@tuni.fi

SELECT gc_name, MIN(duration) AS duration
FROM g_class
ORDER BY gc_name ASC;
