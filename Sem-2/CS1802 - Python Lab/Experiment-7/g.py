# Hanoi Game

def TowerOfHanoi(n , s, a, d):
    if n==1:
        print(f"Moved disk 1 from Tower {s} to Tower {d}")
        return
    TowerOfHanoi(n-1, s, d, a)
    print(f"Moved disk {n} from Tower {s} to Tower {d}")
    TowerOfHanoi(n-1, a, s, d)

n = 5
TowerOfHanoi(n, '1', '2', '3')