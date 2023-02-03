-- viite-eheyden valvonta päälle SQLitessa
-- turn the referencial integrity control on in SQLite

PRAGMA foreign_keys = ON;

-- categories of exercise class

CREATE TABLE category (
    c_id INT,
    c_name VARCHAR(30) NOT NULL,
    PRIMARY KEY (c_id),
    UNIQUE (c_name)
);

-- group exercise classes

CREATE TABLE g_class (
    gc_id INT,
    gc_name VARCHAR(30) NOT NULL,
    description VARCHAR(60) NOT NULL,
    duration INT NOT NULL,
    level INT NOT NULL,
    c_id INT NOT NULL,
    PRIMARY KEY (gc_id),
    UNIQUE (gc_name),
    FOREIGN KEY (c_id) REFERENCES category
);

-- instructors

CREATE TABLE instructor (
    i_id INT,
    i_name VARCHAR(30) NOT NULL,
    date_of_birth DATE NOT NULL,
    PRIMARY KEY (i_id)
);

-- halls

CREATE TABLE hall (
    h_id INT,
    h_name VARCHAR(20) NOT NULL,
    no_places INT NOT NULL,
    PRIMARY KEY (h_id),
    UNIQUE (h_name)
);

-- which classes the instructor can instruct

CREATE TABLE can_instruct (
    i_id INT,
    gc_id INT,
    PRIMARY KEY (i_id, gc_id),
    FOREIGN KEY (i_id) REFERENCES instructor,
    FOREIGN KEY (gc_id) REFERENCES g_class
);

-- classes in timetable

CREATE TABLE tt_class (
    gc_id INT,
    day_of_week VARCHAR(20),
    start_time TIME,
    end_time TIME,
    max_participants INT NOT NULL,
    i_id INT NOT NULL,
    h_id INT NOT NULL,
    PRIMARY KEY (gc_id, day_of_week, start_time),
    FOREIGN KEY (gc_id) REFERENCES g_class,
    FOREIGN KEY (i_id) REFERENCES instructor,
    FOREIGN KEY (h_id) REFERENCES hall
);
