let N = 5;

let M = new Array(N + 2);

let ex = 3;
let ey = 4;
f = 0;
console.log("Start");
for (let i = 0; i < M.length; i++) {
  M[i] = new Array(N + 2);
}

function out(x) {
  let s = "";
  for (let i = 0; i < M.length; i++) {
    const L = M[i];
    for (let j = 0; j < L.length; j++) {
      e = L[j];
      s += e + " ";
      if (M[i][j] == undefined) M[i][j] = x;
    }
    s += "\n";
  }
  console.log(s);
}
out(0);

function dfs(x, y, v) {
  M[x][y] = v;
  if (x == ex && y == ey) {
    t = 0;
    for (let i = 0; i < M.length; i++) {
      const L = M[i];
      for (let j = 0; j < L.length; j++) {
        e = L[j];
        if (e > 0) t++;
      }
    }
    console.log("This time:" + t);
    if (t == N * N) {
      console.log("Success!");
      f = 1;
      out();
    }
  }
  if (M[x - 1][y] == 0 && x - 1 != 0) dfs(x - 1, y, 1);
  if (M[x + 1][y] == 0 && x + 1 != N + 1) dfs(x + 1, y, 2);
  if (M[x][y - 1] == 0 && y - 1 != 0) dfs(x, y - 1, 3);
  if (M[x][y + 1] == 0 && y + 1 != N + 1) dfs(x, y + 1, 4);
  M[x][y] = 0;
}

dfs(1, 3, -1);
dfs(1, 3, -1);
dfs(1, 3, -1);
if (f == 0) console.log("Fail!");
else console.log("Success!");
