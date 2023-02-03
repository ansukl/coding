-- viite-eheyden valvonta päälle SQLitessa
-- turn the referencial integrity control on in SQLite

PRAGMA foreign_keys = ON;

-- jäätelön valmistajia
-- ice cream manufacturers

CREATE TABLE manufacturer (
    manufacturer_id INT,
    manufacturer_name VARCHAR(30) NOT NULL,
    country VARCHAR(30) NOT NULL,
    PRIMARY KEY (manufacturer_id),
    UNIQUE (manufacturer_name)
);

-- jäätelöitä
-- ice creams

CREATE TABLE ice_cream (
    ice_cream_id INT,
    ice_cream_name VARCHAR(30) NOT NULL,
    manufacturer_id INT NOT NULL,
    manufacturing_cost NUMERIC(4,2),
    PRIMARY KEY (ice_cream_id),
    UNIQUE (ice_cream_name),
    FOREIGN KEY (manufacturer_id) REFERENCES manufacturer
);

-- aineksia
-- ingredients
-- plant_based arvo 0 merkitse ei ja arvo 1 merkitsee kyllä
-- plant_based value 0 means no and value 1 means yes 

CREATE TABLE ingredient (
    ingredient_id INT,
    ingredient_name VARCHAR(30) NOT NULL,
    kcal INT,
    protein NUMERIC(3,1),
    plant_based INT,
    PRIMARY KEY (ingredient_id),
    UNIQUE (ingredient_name)
);

-- jäätelöt sisältävät aineksia
-- ice creams contain ingredients

CREATE TABLE contains(
    ice_cream_id INT NOT NULL,
    ingredient_id INT NOT NULL,
    quantity INT,
    PRIMARY KEY (ice_cream_id, ingredient_id),
    FOREIGN KEY (ice_cream_id) REFERENCES ice_cream,
    FOREIGN KEY (ingredient_id) REFERENCES ingredient
);

