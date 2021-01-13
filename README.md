# Build a Hybrid Application beyond x86, using buildah and podman


## Why do we need to consider Multiarch hybrid applications

Enterprises and Large system used to run on Mainframe, a large computer with a large amount of memory, but with increasing Personal Computer (a.k.a) Microcomputer, more CPU started to Mass produced to fit inside a box that lay on the Desktop.

The Microcomputer CPUs started to make their way to Enterprise applications. With the introduction of the distributed system, the x86 machines began to dominate the Enterprise applications with distributed systems' success. Stewart Alsop II famously predicted that the last Mainframe would be unplugged on March 15, 1996. This prediction turns out to be very wrong with IBM introducing IBM Z15 in September 2020. IBM Z and Mainframe turns out to be very much alive and striving. Running a Legacy application very reliable, and the Mainframe is packed with considerable computing power in a small footprint compared to distributed x86_64 systems.

Public Cloud and Hyperscaler become the new normal for hosting Enterprise application, with apparent domination of x86_64 ISA from Intel Xeon and AMD EPYC. Still, the demands for specialized workloads and hosting from businesses make the public cloud provider introduce different Machines such as IBM power, IBM Z, and Amazon ARM.

Nowadays, we are in the Era of 5G and IoT, with increased Edge computing demands, and we raise awareness about the environmental impact of the datacenters and increase needs. Power-efficient machines make ARM machines start to get back to the PC market and move toward Servers and Enterprise Applications.

The previous introduction is trying to demonstrate why there is a need for multiarch deployments; if you are building an application, asset, or even custom enterprise solution, you may still face a demand to deploy it on none x86 machines.

## Introducing Instruction set Architecture (ISA) 
https://www.computerhope.com/jargon/i/instset.htm

The instruction set, also called ISA (instruction set architecture), is part of a computer that pertains to programming, which is more or less machine language. The instruction set provides commands to the processor to tell it what it needs to do. The instruction set consists of addressing modes, instructions, native data types, registers, memory architecture, interrupt and exception handling, and external I/O.

In early 1960, IBM used to have a series of incompatible families, but with the introduction of IBM System 360, the grandparent of IBM Z/Architecture, IBM standardized their Mainframe. IBM System 360 is The	first	true	ISA	designed as a portable hardware-software interface.

## ISA landscape today

Will list the CPU according to the introduction of their first generation.
### IBM Z  
IBM Z is the latest generation of the System/360 introduced in 1964, used exclusively in IBM Z Mainframe.
Still, you do not need to purchase an expensive mainframe to try. IBM Cloud introduces Hyper Protect Virtual Server, https://cloud.ibm.com/catalog/services/hyper-protect-virtual-server 
which gives access to IBM Z Machines running Linux One.
Strengths: Handle Intensive IO operations, such as Credit card swipes.
Definition in Linux: s390x
Trivia: In z/architecture, the Z stands to Zero downtime.

### x86
Developed by Intel and currently produced mainly by Intel and AMD, it provides a large family of processors covering a broad spectrum of mobility, laptop, workstation, and High-Performance Servers.
Strengths: General purpose computing, the defacto standard for all software.
Definition in Linux: i385, x86_64
Trivia: Even Intel is the one who created x86, AMD is the one who defines x86_64, the 64-bit extension, after the limited success of IA_64 in the consumer.

## Power ISA
Developed by the AIM alliance, AIM refers to Apple, IBM, and Motorolla, to create RISC machines. PowerPC used to be the standard CPU in Apple products till 2005. PowerPC was the CPU used in many consumer products such as Playstation 3, xbox360, and Nintendo Wii
Strengths: with IBM power 10, IBM claims its main advantage is to provide faster AI inference.
Definition in Linux: ppc64le, ppc64
Trivia:  Power2 was the CPU used in Deepblue, the first machine to win chess, Kasparov. Also, Power7 was the CPU behind the machine that won the first Jeopardy.

## Options to build multiarch container images
## Explain Qemu user emulation
## Testing Environment.
   * Kubernetes Cluster on ARM64 using VMware ESXi as Hypervisor
   * Mysql on ARM64 on Arm64 Virtual Machines
   * Single node Kubernetes Cluster and Mysql on x86 VM
## Demo
   * Show how to build a multiarch container image using qemu-user-static
   * Show how MySQL replication happens between different Arch
