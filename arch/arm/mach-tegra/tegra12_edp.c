/*
 * arch/arm/mach-tegra/tegra12_edp.c
 *
 * Copyright (c) 2013-2014, NVIDIA CORPORATION. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef CONFIG_ARCH_TEGRA_12x_SOC

#include <linux/tegra-fuse.h>
#include <mach/edp.h>

#if defined(CONFIG_SYSEDP_FRAMEWORK) && !defined(CONFIG_ARCH_TEGRA_13x_SOC)
static struct tegra_sysedp_corecap td580d_sysedp_corecap[] = {
/*
TD580D/CD580M/SD580N
GPU MaxF	853000 KHz
CPU MaxBudget	12000  mW
*/
	/*mW	 CPU intensive load        GPU intensive load    */
	/*mW     budget  gpu(khz) mem(khz)  budget  gpu(khz) mem(khz) pthrot(mW)*/
	{5000,  {1500,  108000, 933000 }, {1500,  108000, 933000 }, 1116 },
	{6000,  {3000,  108000, 933000 }, {3000,  108000, 933000 }, 2109 },
	{7000,  {4000,  108000, 933000 }, {3000,  180000, 933000 }, 2589 },
	{8000,  {5000,  108000, 933000 }, {3000,  252000, 933000 }, 3068 },
	{9000,  {6000,  180000, 933000 }, {2500,  396000, 933000 }, 3630 },
	{10000, {7000,  108000, 933000 }, {3500,  396000, 933000 }, 4425 },
	{11000, {7000,  252000, 933000 }, {4000,  468000, 933000 }, 5301 },
	{12000, {8000,  180000, 933000 }, {3000,  540000, 933000 }, 5348 },
	{13000, {9000,  108000, 933000 }, {5000,  540000, 933000 }, 6969 },
	{14000, {10000, 108000, 933000 }, {3500,  612000, 933000 }, 6846 },
	{15000, {10000, 180000, 933000 }, {4000,  648000, 933000 }, 7880 },
	{16000, {11000, 180000, 933000 }, {3500,  684000, 933000 }, 8120 },
	{17000, {12000, 108000, 933000 }, {4000,  708000, 933000 }, 9024 },
	{18000, {12000, 252000, 933000 }, {3000,  756000, 933000 }, 9252 },
	{19000, {12000, 252000, 933000 }, {4000,  756000, 933000 }, 10046 },
	{20000, {12000, 396000, 933000 }, {5000,  756000, 933000 }, 10873 },
	{21000, {12000, 468000, 933000 }, {3500,  804000, 933000 }, 10909 },
	{22000, {12000, 540000, 933000 }, {4000,  804000, 933000 }, 11306 },
	{23000, {12000, 540000, 933000 }, {4000,  853000, 933000 }, 12696 },
	{24000, {12000, 612000, 933000 }, {5000,  853000, 933000 }, 13524 },
	{25000, {12000, 612000, 933000 }, {5000,  853000, 933000 }, 13524 },
	{26000, {12000, 684000, 933000 }, {6000,  853000, 933000 }, 14452 },
	{27000, {12000, 708000, 933000 }, {7000,  853000, 933000 }, 15002 },
	{28000, {12000, 708000, 933000 }, {8000,  853000, 933000 }, 16030 },
	{29000, {12000, 756000, 933000 }, {8000,  853000, 933000 }, 16311 },
	{30000, {12000, 756000, 933000 }, {8000,  853000, 933000 }, 16311 },
	{31000, {12000, 756000, 933000 }, {8000,  853000, 933000 }, 16311 },
	{32000, {12000, 804000, 933000 }, {9000,  853000, 933000 }, 16883 },
	{33000, {12000, 804000, 933000 }, {10000, 853000, 933000 }, 17721 },
};

static struct tegra_sysedp_corecap td570d_sysedp_corecap[] = {
/*
TD570D/SD570N
GPU MaxF	648000 KHz
CPU MaxBudget	9000   mW
*/
	/*mW	 CPU intensive load        GPU intensive load    */
	/*mW     budget  gpu(khz) mem(khz)  budget  gpu(khz) mem(khz) pthrot(mW)*/
	{5000,  {1500, 108000, 792000 }, {1500, 108000, 792000 }, 918 },
	{6000,  {3000, 108000, 792000 }, {3000, 108000, 792000 }, 2109 },
	{7000,  {4000, 108000, 792000 }, {3000, 180000, 792000 }, 2589 },
	{8000,  {5000, 108000, 792000 }, {3000, 252000, 792000 }, 3068 },
	{9000,  {6000, 180000, 792000 }, {2500, 396000, 792000 }, 3630 },
	{10000, {7000, 108000, 792000 }, {3500, 396000, 792000 }, 4425 },
	{11000, {7000, 252000, 792000 }, {4000, 468000, 792000 }, 5301 },
	{12000, {8000, 180000, 792000 }, {3000, 540000, 792000 }, 5348 },
	{13000, {9000, 108000, 792000 }, {5000, 540000, 792000 }, 6969 },
	{14000, {9000, 180000, 792000 }, {3500, 612000, 792000 }, 6846 },
	{15000, {9000, 252000, 792000 }, {4000, 648000, 792000 }, 7880 },
	{16000, {9000, 396000, 792000 }, {5000, 648000, 792000 }, 8770 },
	{17000, {9000, 468000, 792000 }, {6000, 648000, 792000 }, 9488 },
	{18000, {9000, 468000, 792000 }, {7000, 648000, 792000 }, 9488 },
	{19000, {9000, 540000, 792000 }, {7000, 648000, 792000 }, 10185 },
	{20000, {9000, 612000, 792000 }, {7000, 648000, 792000 }, 10185 },
	{21000, {9000, 612000, 792000 }, {8000, 648000, 792000 }, 10804 },
	{22000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{23000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{24000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{25000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{26000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{27000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{28000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{29000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{30000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{31000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{32000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
	{33000, {9000, 648000, 792000 }, {9000, 648000, 792000 }, 12066 },
};

static struct tegra_sysedp_corecap td575d_sysedp_corecap[] = {
/*
TD575D/CD575M/SD575N
GPU MaxF	853000 KHz
CPU MaxBudget	10000  mW
*/
	/*mW	 CPU intensive load        GPU intensive load    */
	/*mW     budget  gpu(khz) mem(khz)  budget  gpu(khz) mem(khz) pthrot(mW) */
	{5000,  {1500,  108000, 933000}, {1500,  108000, 933000 }, 918 },
	{6000,  {3000,  108000, 933000}, {3000,  108000, 933000 }, 2109 },
	{7000,  {4000,  108000, 933000}, {3000,  180000, 933000 }, 2589 },
	{8000,  {5000,  108000, 933000}, {3000,  252000, 933000 }, 3068 },
	{9000,  {6000,  180000, 933000}, {2500,  396000, 933000 }, 3630 },
	{10000, {7000,  108000, 933000}, {3500,  396000, 933000 }, 4425 },
	{11000, {7000,  252000, 933000}, {4000,  468000, 933000 }, 5301 },
	{12000, {8000,  180000, 933000}, {3000,  540000, 933000 }, 5348 },
	{13000, {9000,  108000, 933000}, {5000,  540000, 933000 }, 6969 },
	{14000, {10000, 108000, 933000}, {3500,  612000, 933000 }, 6846 },
	{15000, {10000, 180000, 933000}, {4000,  648000, 933000 }, 7880 },
	{16000, {10000, 252000, 933000}, {3500,  684000, 933000 }, 8120 },
	{17000, {10000, 396000, 933000}, {4000,  708000, 933000 }, 9024 },
	{18000, {10000, 396000, 933000}, {3000,  756000, 933000 }, 9252 },
	{19000, {10000, 468000, 933000}, {4000,  756000, 933000 }, 10046 },
	{20000, {10000, 540000, 933000}, {5000,  756000, 933000 }, 10873 },
	{21000, {10000, 540000, 933000}, {3500,  804000, 933000 }, 10909 },
	{22000, {10000, 612000, 933000}, {4000,  804000, 933000 }, 11306 },
	{23000, {10000, 648000, 933000}, {4000,  853000, 933000 }, 12696 },
	{24000, {10000, 708000, 933000}, {5000,  853000, 933000 }, 13524 },
	{25000, {10000, 708000, 933000}, {5000,  853000, 933000 }, 13524 },
	{26000, {10000, 708000, 933000}, {6000,  853000, 933000 }, 14049 },
	{27000, {10000, 756000, 933000}, {7000,  853000, 933000 }, 15002 },
	{28000, {10000, 756000, 933000}, {8000,  853000, 933000 }, 15071 },
	{29000, {10000, 804000, 933000}, {8000,  853000, 933000 }, 15621 },
	{30000, {10000, 804000, 933000}, {8000,  853000, 933000 }, 15621 },
	{31000, {10000, 804000, 933000}, {8000,  853000, 933000 }, 15621 },
	{32000, {10000, 804000, 933000}, {9000,  853000, 933000 }, 16331 },
	{33000, {10000, 853000, 933000}, {10000, 853000, 933000 }, 17721 },
};

static struct tegra_sysedp_corecap cd570m_sysedp_corecap[] = {
/*
CD570M
GPU MaxF	648000 KHz
CPU MaxBudget	10000  mW
*/
	/*mW	 CPU intensive load        GPU intensive load    */
	/*mW     budget  gpu(khz) mem(khz)  budget  gpu(khz) mem(khz) pthrot(mW)*/
	{5000,  {1500,  108000, 933000}, {1500,  108000, 933000}, 918 },
	{6000,  {3000,  108000, 933000}, {3000,  108000, 933000}, 2109 },
	{7000,  {4000,  108000, 933000}, {3000,  180000, 933000}, 2589 },
	{8000,  {5000,  108000, 933000}, {3000,  252000, 933000}, 3068 },
	{9000,  {6000,  180000, 933000}, {2500,  396000, 933000}, 3630 },
	{10000, {7000,  108000, 933000}, {3500,  396000, 933000}, 4425 },
	{11000, {7000,  252000, 933000}, {4000,  468000, 933000}, 5301 },
	{12000, {8000,  180000, 933000}, {3000,  540000, 933000}, 5348 },
	{13000, {9000,  108000, 933000}, {5000,  540000, 933000}, 6969 },
	{14000, {10000, 108000, 933000}, {3500,  612000, 933000}, 6846 },
	{15000, {10000, 180000, 933000}, {4000,  648000, 933000}, 7880 },
	{16000, {10000, 252000, 933000}, {5000,  648000, 933000}, 8707 },
	{17000, {10000, 396000, 933000}, {6000,  648000, 933000}, 9636 },
	{18000, {10000, 396000, 933000}, {7000,  648000, 933000}, 9846 },
	{19000, {10000, 468000, 933000}, {7000,  648000, 933000}, 10185 },
	{20000, {10000, 540000, 933000}, {7000,  648000, 933000}, 10185 },
	{21000, {10000, 540000, 933000}, {8000,  648000, 933000}, 10804 },
	{22000, {10000, 612000, 933000}, {9000,  648000, 933000}, 12904 },
	{23000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{24000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{25000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{26000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{27000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{28000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{29000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{30000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{31000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{32000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
	{33000, {10000, 648000, 933000}, {10000, 648000, 933000}, 12904 },
};

struct tegra_sysedp_corecap *tegra_get_sysedp_corecap(unsigned int *sz)
{
	int cpu_speedo_id;
	int gpu_speedo_id;

	BUG_ON(sz == NULL);

	cpu_speedo_id = tegra_cpu_speedo_id();
	gpu_speedo_id = tegra_gpu_speedo_id();

	switch (cpu_speedo_id) {
	case 0x6:
	case 0x5:
	case 0x2:
		if (gpu_speedo_id == 1) {
			/* 575 variants */
			*sz = ARRAY_SIZE(td575d_sysedp_corecap);
			return td575d_sysedp_corecap;
		} else {
			/* CD570M */
			*sz = ARRAY_SIZE(cd570m_sysedp_corecap);
			return cd570m_sysedp_corecap;
		}

	case 0x3:
	case 0x1:
		/* 580 variants */
		*sz = ARRAY_SIZE(td580d_sysedp_corecap);
		return td580d_sysedp_corecap;


	default:
		pr_warn("%s: Unknown cpu_speedo_id, 0x%x. "
			" Assuming td570d sysedp_corecap table.\n",
			__func__, cpu_speedo_id);
		/* intentional fall-through */
	case 0x0:
		/* 570 variants */
		*sz = ARRAY_SIZE(td570d_sysedp_corecap);
		return td570d_sysedp_corecap;
	}
}
#endif

#ifdef CONFIG_TEGRA_EDP_LIMITS

#ifdef CONFIG_TEGRA_GPU_EDP
static struct tegra_edp_gpu_powermodel_params t12x_gpu_powermodel_params = {
	.common = {
		.temp_scaled      = 10,
		.dyn_scaled       = 1000,
		.dyn_consts_n     = { 10646, },
		.consts_scaled    = 1,
		.leakage_consts_n = { 1, },
		.ijk_scaled       = 100000,
		.leakage_min      = 30,
		.leakage_consts_ijk = {
			/* i = 0 */
			{ {  -208796792,   37746202,  -9648869,   725660, },
			  {   704446675, -133808535,  34470023, -2464142, },
			  {  -783701649,  146557393, -38623024,  2654269, },
			  {   292709580,  -51246839,  13984499,  -934964, },
			},
			/* i = 1 */
			{ {   115095343,  -65602614,  11251896,  -838394, },
			  {  -394753929,  263095142, -49006854,  3326269, },
			  {   441644020, -313320338,  61612126, -3916786, },
			  {  -164021554,  118634317, -24406245,  1517573, },
			},
			/* i = 2 */
			{ {   -38857760,   12243796,  -1964159,   181232, },
			  {   143265078,  -71110695,  13985680,  -917947, },
			  {  -171456530,   98906114, -21261015,  1216159, },
			  {    67437536,  -40520060,   9265259,  -484818, },
			},
			/* i = 3 */
			{ {     1795940,    -345535,     83004,   -20007, },
			  {    -8549105,    6333235,  -1479815,   115441, },
			  {    12192546,  -10880741,   2632212,  -161404, },
			  {    -5328587,    4953756,  -1215038,    64556, },
			},
		},
	},
};

struct tegra_edp_gpu_powermodel_params *tegra12x_get_gpu_powermodel_params(void)
{
	return &t12x_gpu_powermodel_params;
}

#endif /* CONFIG_TEGRA_GPU_EDP */

#if !defined(CONFIG_ARCH_TEGRA_13x_SOC)
#define LEAKAGE_CONSTS_IJK_COMMON					\
{									\
	/* i = 0 */							\
	{ {  -309609464,    197786326,    -40763150,    1613941, },	\
	  {   964716269,   -569081375,    115781607,   -4206296, },	\
	  {  -994324790,    529664031,   -106360108,    3454033, },	\
	  {   343209442,   -160577505,     31928605,    -895157, },	\
	},								\
	/* i = 1 */							\
	{ {   616319664,   -637007187,    137759592,    -7194133,  },	\
	  { -1853817283,   1896032851,   -407407611,    20868220,  },	\
	  {  1824097131,  -1831611624,    390753403,   -19530122,  },	\
	  {  -589155245,    578838526,   -122655676,     5985577,  },	\
	},								\
	/* i = 2 */							\
	{ {  -439994037,    455845250,   -104097013,     6191899, },	\
	  {  1354650774,  -1395561938,    318665647,   -18886906, },	\
	  { -1361677255,   1390149678,   -317474532,    18728266, },	\
	  {   447877887,   -451382027,    103201434,    -6046692, },	\
	},								\
	/* i = 3 */							\
	{ {    56797556,    -59779544,     13810295,     -848290, },	\
	  {  -175867301,    184753957,    -42708242,     2621537, },	\
	  {   177626357,   -185996541,     43029384,    -2638283, },	\
	  {   -58587547,     61075322,    -14145853,      865351, },	\
	},								\
}

#define EDP_PARAMS_COMMON_PART						\
{									\
	.temp_scaled      = 10,						\
	.dyn_scaled       = 1000,					\
	.dyn_consts_n     = { 950,  1399, 2166, 3041 },			\
	.consts_scaled    = 100,					\
	.leakage_consts_n = { 45, 67, 87, 100 },			\
	.ijk_scaled       = 100000,					\
	.leakage_min      = 30,						\
	/* .volt_temp_cap = { 70, 1240 }, - TODO for T124 */		\
	.leakage_consts_ijk = LEAKAGE_CONSTS_IJK_COMMON			\
}

static struct tegra_edp_cpu_powermodel_params t12x_cpu_powermodel_params[] = {
	{
		.cpu_speedo_id = 0, /* Engg SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
	{
		.cpu_speedo_id = 1, /* Prod SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
	{
		.cpu_speedo_id = 2, /* Prod SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
	{
		.cpu_speedo_id = 3, /* Prod SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
	{
		.cpu_speedo_id = 5, /* Prod SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
	{
		.cpu_speedo_id = 6, /* Prod SKU */
		.common = EDP_PARAMS_COMMON_PART,
	},
};

struct tegra_edp_cpu_powermodel_params *tegra12x_get_cpu_powermodel_params(
							int index,
							unsigned int *sz)
{
	BUG_ON(index >= ARRAY_SIZE(t12x_cpu_powermodel_params));
	if (sz)
		*sz = ARRAY_SIZE(t12x_cpu_powermodel_params);
	return &t12x_cpu_powermodel_params[index];
}
#endif /* CONFIG_ARCH_TEGRA_12x_SOC && !CONFIG_ARCH_TEGRA_13x_SOC */

#endif /* CONFIG_TEGRA_EDP_LIMITS */

#endif /* CONFIG_ARCH_TEGRA_12x_SOC */