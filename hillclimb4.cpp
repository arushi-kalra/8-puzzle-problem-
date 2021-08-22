#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
/*int hammingDistance(int (*start)[3], int (*goal)[3]) {
  int setBits, s = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int x = start[i][j] ^ goal[i][j];
      setBits = 0;

      while (x > 0) {
        setBits += x & 1;
        x >>= 1;
      }

      s = s + setBits;
    }
  }
  return s;

}*/
void copy1(int(*start)[3],int (*start1)[3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            start[i][j]=start1[i][j];
        }
    }
}
int manhattanDistance(int (*start)[3], int (*goal)[3]) {
  int dist = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(start[i][j]!=0 && start[i][j]!=goal[i][j])
      dist++;
    }
  }
  return dist;
}
void up(int (*start)[3]) {
  int i, j, f1 = 0, x, y;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (start[i][j] == 0) {
        x = i;
        y = j;
        f1 = 1;
        break;
      }
      if (f1 == 1)
        break;
    }
  }
  if (x != 0)
    swap(&start[x][y], &start[x - 1][y]);
  // cout<<start[x]y]<<endl;
}
void down(int (*start)[3]) {
  int i, j, f2 = 0, x, y;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (start[i][j] == 0) {
        x = i;
        y = j;
        f2 = 1;
        break;
      }
      if (f2 == 1)
        break;
    }
  }
  // cout<<x<<"a"<<y<<endl;
  if (x != 2)
    // cout<<"c"<<endl;
    swap(&start[x][y], &start[x + 1][y]);
  // cout<<start[x][y]<<endl;
}
void left(int (*start)[3]) {
  int i, j, f3 = 0, x, y;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (start[i][j] == 0) {
        x = i;
        y = j;
        f3 = 1;
        break;
      }
      if (f3 == 1)
        break;
    }
  }
  if (y != 0)
    swap(&start[x][y], &start[x][y - 1]);
}
void right(int (*start)[3]) {
  int i, j, f4 = 0, x, y;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (start[i][j] == 0) {
        x = i;
        y = j;
        f4 = 1;
        break;
      }
      if (f4 == 1)
        break;
    }
  }
  if (y != 2)
    swap(&start[x][y], &start[x][y + 1]);
}
void print(int (*start)[3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << start[i][j] << " ";
    }
    cout << endl;
  }
}
void hillclimb(int (*start)[3], int (*goal)[3], int (*start1)[3]) {
  int h_val, h_val_next = 0, f = 0;
  // stack<int**>s;
  // int (*state)[3];
  // s.push(start);
  bool nxt = true;
  while (nxt == true) {
    // state=s.top();
    // s.pop();
    print(start);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++)

      {
        if (start[i][j] != goal[i][j]) {
          //cout<<"q"<<endl;
          f = 1;
          break;
        }
      }
      if(f==1)
      break;
    }
    if (f != 1) {
      cout << "solution reached" << endl;
      break;
    }
    h_val = manhattanDistance(start, goal) ;
    up(start);
    print(start);
    h_val_next = manhattanDistance(start, goal);
    cout << h_val_next << " " << h_val << "a" << endl;
    if (h_val_next < h_val) {

      h_val = h_val_next;
      nxt = true;
      f=0;
      copy1(start1,start);
      // s.push(start);
      continue;

    } else {
      copy1(start,start1);
     // print(start);
      nxt = false;
    }
    //cout<<"ab"<<endl;
   // print(start1);
    cout<<"cd"<<endl;
    down(start);
    //cout<<"q"<<endl;
   // print(start1);
    print(start);
    //cout<<"ef"<<endl;
    //print(start1);
    h_val_next = manhattanDistance(start, goal) ;
    cout << h_val_next << " " << h_val << "b" << endl;
    // cout<<h_val_next<<endl;
    // cout<<h_val<<endl;
    if (h_val_next < h_val) {
      // cout<<"a"<<endl;
      h_val = h_val_next;
      nxt = true;
      f=0;
      copy1(start1,start);
      // s.push(start);
      continue;

    }

    else {
      copy1(start,start1);
      //print(start1);
     // print(start);
      nxt = false;
    }
    /*  for(int i=0;i<3;i++)
  {
      for(int j=0;j<3;j++)
      cout<<start[i][j]<<" ";
      cout<<endl;
  }*/
  print(start);
    right(start);
    print(start);
    h_val_next = manhattanDistance(start, goal) ;
    cout << h_val_next << " " << h_val << "c" << endl;
    if (h_val_next < h_val) {

      h_val = h_val_next;
      nxt = true;
      // s.push(start);
      f=0;
      copy1(start1,start);
      continue;

    } else {
      copy1(start,start1);
      nxt = true;
    }
    left(start);
    print(start);
    h_val_next = manhattanDistance(start, goal) ;
    cout << h_val_next << " " << h_val << "d" << endl;
    if (h_val_next < h_val) {

      h_val = h_val_next;
      // s.push(start);
      nxt = true;
      f=0;
      copy1(start1,start);
      continue;

    } else {

      copy1(start,start1);
      nxt = false;
    }
  }
  if (f == 1)
    cout << "no soln" << endl;
}
int main() {
  int st1[3][3] = {{1,2,3}, {5,6,0}, {7,8,4}};
  int st[3][3] = {{1, 2, 3}, {5,6,0}, {7,8,4}};
 // int st[3][3] = {{3, 1, 2}, {4, 5, 8}, {6, 0, 7}};
  int goal1[3][3] = {{1,2,3}, {5,8,6}, {0,7,8}};
  hillclimb(st, goal1, st1);
  return 0;
}

