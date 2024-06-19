// https://www.acmicpc.net/problem/22993
// 서든어택3

// 문제
// 지스타를 준비하기 시작한 작년 여름 이후 CBT와 런칭 준비를 한 오늘까지. 평일 저녁에 가족이 깨어 있는 것을 거의 본 적이 없다.
// 이제 본격적인 정식오픈을 이틀 앞 둔 오늘. 바람소리와 스산한 빗소리가 사무실 창밖을 때린다.
// 폭풍전야.
// 블라인드에서 서든3을 비웃던, 지금도 비웃는 이들에게 반박글을 달지 않았다. 
// 니들이 허접한지, 우리가 허접한지는 결과가 말해줄 것이다.

// 넥슨의 게임 개발자 준원이는 서든어택 3의 출시를 앞두고 게임 테스트를 하고 있다.
// 맵에는 준원이를 포함해 N명의 플레이어가 있다. 준원이의 공격력은 A_1이고, 나머지 사람들의 공격력은 A_2, ... , A_N이다.
// 전투가 시작되면 누구나 누구든 공격할 수 있게 된다! 죽은 사람은 공격하거나 공격받지 못하고, 두 사람이 동시에 공격하는 일은 일어나지 않는다.
// 공격력이 X인 플레이어 A가 공격력이 Y인 플레이어 B를 공격하면,

// X > Y 이면, B가 죽고 A의 공격력은 X+Y가 된다.$X < Y$ 이면, A가 죽고 B의 공격력은 X+Y가 된다. X = Y 이면, 아무 일도 일어나지 않는다.
// 드디어 전투가 시작되었다! 준원이는 최후의 생존자가 될 수 있을까?

// 입력
// 첫째 줄에는 준원이를 포함한 플레이어의 수 N이 주어진다.
// 둘째 줄에는 각 플레이어의 공격력 A_1, ... , A_N이 차례대로 공백을 사이에 두고 주어진다.

// 출력
// 좋은 전투 순서가 존재해서 준원이만 생존하고 나머지 플레이어가 모두 죽게 만들 수 있다면 Yes를,
// 반대로 전투가 어떤 순서로 이루어져도 준원이가 절대 최후의 생존자가 될 수 없다면 No를 출력한다.

// 제한
// 1 <= N <= 100000, 1 <= A_i <= 1,000,000,000 (1 <= i <= N)
// 예제 입력 1 
// 5
// 2 1 2 3 4
// 예제 출력 1 
// Yes
// 예제 입력 2 
// 5
// 2 1 1 1 10
// 예제 출력 2 
// No

const fs = require("fs")
const filePath = process.platform === "linux" ? '/dev/stdin' : "/input.txt";
const input = fs.readFileSync(__dirname + filePath).toString().trim().split("\n");

function main() {
    let a = parseInt(input[0]);
    let players = input[1].split(" ").map(Number);
    let atk = players[0];
    players = players.slice(1).sort((a,b) => a-b);
    for (let i = 0; i < (a-1); i++) {
        if (atk > 1000000000) return ("Yes");
        if (atk > players[i]) atk += players[i];
        else return ("No");
    }
    return ("Yes");
}

console.log(main());