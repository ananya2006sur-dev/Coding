from collections import defaultdict, deque
from typing import List


def recommend_connections(
    friendships: List[List[int]],
    t: int,
    k: int = 3,
) -> List[int]:
    """
    Recommend up to k people for user t.

    Candidates: not t, not already friends with t, but reachable
    through the friendship network (friends-of-friends or farther).

    Ranking:
      1. Closer distance first (2 hops before 3, etc.)
      2. More mutual friends with t
      3. Smaller user id (tie-break)
    """
    graph = defaultdict(set)
    for u, v in friendships:
        if u == v:
            continue
        graph[u].add(v)
        graph[v].add(u)

    if t not in graph:
        return []

    friends_of_t = graph[t]

    # BFS from t to find distance to every reachable user
    dist = {t: 0}
    q = deque([t])
    while q:
        user = q.popleft()
        for nei in graph[user]:
            if nei not in dist:
                dist[nei] = dist[user] + 1
                q.append(nei)

    def mutual_count(candidate: int) -> int:
        return len(friends_of_t & graph[candidate])

    candidates = []
    for user, d in dist.items():
        # skip self and direct friends; keep distance >= 2
        if user == t or d < 2:
            continue
        candidates.append((d, -mutual_count(user), user))

    candidates.sort()  # closer, then more mutuals, then smaller id
    return [user for _, _, user in candidates[:k]]


if __name__ == "__main__":
    friendships = [
        [1, 2],
        [1, 3],
        [1, 4],
        [2, 5],
        [3, 5],
        [4, 6],
        [5, 7],
        [6, 8],
    ]
    t = 1
    print(recommend_connections(friendships, t))
    # Possible output: [5, 6, 7]
    # 5 = friend of friends 2 and 3 (2 mutuals, distance 2)
    # 6 = friend of friend 4 (1 mutual, distance 2)
    # 7 = farther link via 5 (distance 3)
