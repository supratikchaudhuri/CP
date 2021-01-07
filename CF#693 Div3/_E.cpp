// 1472E - Correct Placement
// Let's sort all people by their height in descending order.

// Now let's go through all the people and look for the position of the person in the sorted array, the height of which is strictly less than ours (for example, by binary search). Obviously, only those people who are in the sorted array later than the found person can stand in front of us (all of them have a height strictly less than ours).

// Among all these people, it is more profitable for us to take a person with minimum width. In order to find such a person quickly, we can find a person with the minimum width for each suffix of the sorted array.

// To handle a situation where a person is lying down, we need to swap the width and height and repeat the algorithm above.