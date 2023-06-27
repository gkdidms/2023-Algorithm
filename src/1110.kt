import java.util.*

fun main() {
    var first = readLine()!!
    if (first.toInt() < 10) first = first.plus("0")
    var newNum = first
    var cycle = 0
    while (true) {
        val list = newNum.split("")
        val newNumPlus = (list[1].toInt() + list[2].toInt()).toString().split("")
        if (newNumPlus.size == 3) {
            newNum = list[2].plus(newNumPlus[1])
        } else {
            newNum = list[2].plus(newNumPlus[2])
        }

        cycle += 1

        if (first == newNum) {
            return print(cycle)
        }
    }
}