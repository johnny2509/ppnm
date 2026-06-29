CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

EXE = main_open main_quad

generated_data = \
	erf_acc_open.dat \
	erf_plot_open.dat \
	sqrt_calls_open.dat \
	invsqrt_calls_open_cc.dat \
	nested_calls_open.dat \
	ln_sqrt_calls_open_cc.dat \
	erf_calls_quad.dat \
	sqrt_calls_quad.dat \
	inv_sqrt_calls_quad_cc.dat \
	nested_calls_quad.dat \
	ln_sqrt_calls_quad_cc.dat

generated_plots = \
	erf_plot_open.pdf \
	erf_plot_open_acc.pdf \
	plot_erf_calls.pdf \
	plot_sqrt_calls.pdf \
	plot_nested_calls.pdf \
	plot_invsqrt_calls.pdf \
	plot_ln_sqrt_calls.pdf

.PHONY: all data plots clean run_open run_quad

all: data plots

main_open: main_open.cc integ_open.hpp
	$(CXX) $(CXXFLAGS) -o main_open main_open.cc

main_quad: main_quad.cc quadinteg.hpp
	$(CXX) $(CXXFLAGS) -o main_quad main_quad.cc

run_open: main_open
	./main_open

run_quad: main_quad
	./main_quad

data: run_open run_quad

plots: data
	gnuplot plot_erf_open.gp
	gnuplot plot_erf_open_conv.gp
	gnuplot plot_erf_calls.gp
	gnuplot plot_sqrt_calls.gp
	gnuplot plot_nested_calls.gp
	gnuplot plot_invsqrt_calls.gp
	gnuplot plot_ln_sqrt_calls.gp

clean:
	rm -f $(EXE) $(generated_data) $(generated_plots)