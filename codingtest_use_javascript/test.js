var message = "Hello JavaScript";
console.log(message)
let check = []; // 방문점을 체크하기 위한 배열

// 배열안에 배열구조로 인접 정점을 담기
let arr = [[], [], [], [], [], [], [], []]; 

function bfsFunction(start) {
    let queue = []; // queue를 쓰진 않았으나 queue처럼 사용하겠다.
    queue.push(start);
    check[start] = true;

    while(queue.length > 0){ // queue안이 비어있지 않을 때까지 루프
        let x = queue[0]; // queue의 front -> 0번 인덱스
        queue.splice(0, 1); // queue의 pop -> 맨 앞 인덱스 제거
        console.log(x); 
        for(let i=0; i<arr[x].length; i++){ // 인접 정점 탐색
            let y = arr[x][i]; 
            if(!check[y]){ // 인접 정점을 방문하지 않았다면
                queue.push(y); // queue에 넣고
                check[y] = true; // 방문 체크
            }
        }
    }
}

// 1과 2연결 
arr[1].push(2);
arr[2].push(1);

// 1과 3연결
arr[1].push(3);
arr[3].push(1);

// 2와 3연결
arr[2].push(3);
arr[3].push(2);

// 2와 4연결
arr[2].push(4);
arr[4].push(2);

// 2와 5연결
arr[2].push(5);
arr[5].push(2);

// 3과 6연결
arr[3].push(6);
arr[6].push(3);

// 3과 7연결
arr[3].push(7);
arr[7].push(3);

// 4와 5연결
arr[4].push(5);
arr[5].push(4);

// 6과 7연결
arr[6].push(7);
arr[7].push(6);

bfsFunction(1); // 1 2 3 4 5 6 7