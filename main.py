import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
import os

# Reading the crop dataset
crop_dataset = pd.read_csv("cropdata.csv")

while True:
    # Reading user input file
    print()
    user_input_file = input("Enter the name of the input file: ")

    # Check if file exists
    if not os.path.exists(user_input_file):
        print()
        print("File not found!")
        continue

    # Flag variable to check if a valid line is found
    valid_line_found = False

    # Reading user input values
    with open(user_input_file) as f:
        for line in f:
            line_values = line.strip().split(',')
            if len(line_values) == 4:
                moisture, temperature, humidity, ph = map(float, line_values)
                valid_line_found = True
                break

    # Check if a valid line is found
    if not valid_line_found:
        print()
        print("Invalid data in file!")
    else:
        # Print message based on moisture value
        if moisture < 10:
            print()
            print("VERY DRY SOIL! MOISTURE IS NOT GOOD")
        elif moisture < 60:
            print()
            print("USEFUL SOIL! MOISTURE IS GOOD")
        elif moisture < 80:
            print()
            print("LITTLE BIT WET SOIL! BUT USEFUL")
        else:
            print()
            print("WET SOIL!")

        # Preparing data for KNN algorithm
        X = crop_dataset.iloc[:, :-1].values
        y = crop_dataset.iloc[:, -1].values

        # Training the KNN model
        knn = KNeighborsClassifier(n_neighbors=5)
        knn.fit(X, y)

        # Predicting the crop based on user input values
        values = [temperature, humidity, ph]
        predicted_crop = knn.predict([values])[0]

        # Displaying predicted crop
        print()
        print("RECOMMENDED CROP FOR YOUR SOIL IS:-- ", predicted_crop)

    # Ask user if they want to continue
    print()
    choice = input("Do you want to continue? (y/n): ")
    if choice.lower() != 'y':
        print()
        print("THANK YOU FOR TEST!")
        break
