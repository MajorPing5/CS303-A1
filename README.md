# CS303-A1

Sample .txt files have been provided for ease of access and testing.
-----------------------------------------------------------How to use----------------------------------------------------------

Note: In order for the program to work, you must use a file with the name "dataFile.txt" and place it within your repository (image as follows). Failure to do so will result in the error "Data File not found." 

![image](https://user-images.githubusercontent.com/24641567/235332998-0320bb0e-b9a5-43ee-a12e-b3b6b0ae5ce3.png)

Once the file has been placed and named appropriately, follow the prompts given within the window of the Terminal.
All inputs are case sensitive, so any accidental inputs with characters in place of numbers will result in the whole program crashing in an unrecoverable state.

After each successful input, the array will be displayed to help the user keep track of the information currently within the array.

1. In the case of searching for a specific value within the data, type 1 when prompted for your option. A second input will be required for the target integer to be searched.

![image](https://user-images.githubusercontent.com/24641567/235333188-a41ce298-625c-4da7-8c46-6ebc508127a8.png)

Should the search be successful, you will receive a confirmation display as shown above. Failure to find the integer will result in the following:

![image](https://user-images.githubusercontent.com/24641567/235333218-022adf1a-e29f-4c7c-b45a-736d9d5b5696.png)

2. In the case of seeking insertion into the array, type 2 when prompted for your option at the main menu. You will be prompted with an input for the array index, before a confirmation window will verify if the input you wanted was correct (as follows):

![image](https://user-images.githubusercontent.com/24641567/235333274-2d9ee2c4-be2c-4874-93a9-813ed87523cf.png)

If the input was an error, type N and you will be sent back to the main menu to either try a different option or retry changing the input as indicated below:

![image](https://user-images.githubusercontent.com/24641567/235334260-242306ab-b340-4d3f-a592-973481230a9a.png)

This UI is consistent throughout all options, and is intended to ensure changes are made with certainty.

A successful insertion into the array should look as the following:

![image](https://user-images.githubusercontent.com/24641567/235334363-2bdec31b-31ef-4c71-b0fb-3d536bf76f50.png)

A successful deletion of the array will look as follows (with array display to confirm to user the success):

![image](https://user-images.githubusercontent.com/24641567/235334396-780cd6ab-a5e7-4670-8f4f-4eb495c34689.png)

The search option operates on a Linear Sequential Search Algorithm, and stops at the first positive incident.
When you are ready to quit, type 5 in the main menu and it will prompt you one last time with a proper shutdown message:

![image](https://user-images.githubusercontent.com/24641567/235334703-d6a5b756-3a2e-4e2d-8b09-a032aa73dc52.png)

The output file will be titled dataOutput.txt, located in the exact location as the dataFile.txt.
