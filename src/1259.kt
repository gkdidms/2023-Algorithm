import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val stringList = ArrayList<String>()
    while (true) {
        val input = readLine()!!
        if (input == "0") break
        stringList.add(input)
    }

    stringList.forEach {
        val reverseInput = it.reversed()
        if (it == reverseInput) {
            println("yes")
        } else {
            println("no")
        }
    }

}