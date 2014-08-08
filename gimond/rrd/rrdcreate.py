#!/usr/bin/python2

import sys
import rrdtool

def main():
	rrdtool.create("sent.rrd", "--step", "60", "--start", '0',
	"DS:all:COUNTER:600:U:U",
	"DS:rrdtool:COUNTER:600:U:U",
	"DS:rrdcached:COUNTER:600:U:U",
	"DS:graphite:COUNTER:600:U:U",
	"DS:memcached:COUNTER:600:U:U",
	"DS:riemann:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("sent_time.rrd", "--step", "60", "--start", '0',
	"DS:all:COUNTER:600:U:U",
	"DS:rrdtool:COUNTER:600:U:U",
	"DS:rrdcached:COUNTER:600:U:U",
	"DS:graphite:COUNTER:600:U:U",
	"DS:memcached:COUNTER:600:U:U",
	"DS:riemann:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("poll.rrd", "--step", "60", "--start", '0',
	"DS:ok:COUNTER:600:U:U",
	"DS:failed:COUNTER:600:U:U",
	"DS:misses:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("poll_time.rrd", "--step", "60", "--start", '0',
	"DS:ok:COUNTER:600:U:U",
	"DS:failed:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("sumrz.rrd", "--step", "60", "--start", '0',
	"DS:cluster:COUNTER:600:U:U",
	"DS:root:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("sumrz_time.rrd", "--step", "60", "--start", '0',
	"DS:all:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("requests.rrd", "--step", "60", "--start", '0',
	"DS:all:COUNTER:600:U:U",
	"DS:interactive:COUNTER:600:U:U",
	"DS:xml:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("requests_time.rrd", "--step", "60", "--start", '0',
	"DS:all:COUNTER:600:U:U",
	"DS:interactive:COUNTER:600:U:U",
	"DS:xml:COUNTER:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("cpu.rrd", "--step", "60", "--start", '0',
	"DS:user:GAUGE:600:U:U",
	"DS:nice:GAUGE:600:U:U",
	"DS:system:GAUGE:600:U:U",
	"DS:idle:GAUGE:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")
	rrdtool.create("received.rrd", "--step", "60", "--start", '0',
	"DS:metrics:GAUGE:600:U:U",
	"RRA:AVERAGE:0.5:1:600",
	"RRA:AVERAGE:0.5:6:700",
	"RRA:AVERAGE:0.5:24:775",
	"RRA:AVERAGE:0.5:288:797",
	"RRA:MAX:0.5:1:600",
	"RRA:MAX:0.5:6:700",
	"RRA:MAX:0.5:24:775",
	"RRA:MAX:0.5:444:797")

if __name__ == "__main__":
	main()
