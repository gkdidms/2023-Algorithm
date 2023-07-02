import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.collections.ArrayList

fun main() {
    val buffer = BufferedReader(InputStreamReader(System.`in`))
    val quantity = buffer.readLine()!!.toInt()
    val rooms =  ArrayList<Int>()
    repeat(quantity) {
        val read = buffer.readLine()!!.toInt()

        rooms.add(read)
    }


    rooms.forEach {
        val roomList = ArrayList<Boolean>()
        repeat(it+1) {
            roomList.add(false)
        }

        for (i in 2 .. it) {
            for (n in i .. it step i) {
                roomList[n] = if (n > 2) !roomList[n] else true
            }
        }
        println(roomList.count { !it }-1)
    }
}