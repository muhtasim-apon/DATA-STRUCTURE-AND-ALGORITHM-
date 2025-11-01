
// int main()
// {
//     int choice = 0;
//     do
//     {
//         printf("\nEnter your Choice:\n1.push\n2.pop\n3.top\n4.check empty\n5.display stack\n6.Exit\n");
//         cin >> choice;

//         switch (choice)
//         {
//         case 1:
//         {
//             printf("Enter value to push in stack\n");
//             int x;
//             cin >> x;
//             push(x);
//             break;
//         }
//         case 2:
//         {
//             int val = pop();
//             if (val == -1)
//                 printf("Stack is Empty!!\n");
//             else
//                 printf("Popped value is %d\n", val);
//             break;
//         }
//         case 3:
//         {
//             int val = top();
//             if (val == -1)
//                 printf("Stack is Empty!!\n");
//             else
//                 printf("Top value is %d\n", val);
//             break;
//         }
//         case 4:
//         {
//             if (isEmpty())
//                 printf("Stack is Empty!!\n");
//             else
//                 printf("Stack is Not Empty!!\n");
//             break;
//         }
//         case 5:
//         {
//             dispalystack();
//             break;
//         }
//         case 6:
//         {
//             exit(0);
//         }
//         default:
//         {
//             printf("Invalid Choice!!\n");
//         }
//         }
//     } while (choice != 6 && choice >= 1 && choice <= 5);

//     return 0;
// }
